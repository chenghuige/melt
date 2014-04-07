/**
 *  ==============================================================================
 *
 *          \file   Numeric/Vector/Vector.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-26 10:46:03.965585
 *
 *  \Description:  特征的核心表示
 *								 支持读写，dense and sparse  可以增加支持binary 比如value为空表示binary
 *                 暂时不增加 感觉意义不大@TODO
 *  ==============================================================================
 */

#ifndef NUMERIC__VECTOR__VECTOR_H_
#define NUMERIC__VECTOR__VECTOR_H_
#include "common_util.h"
namespace gezi {

	class Vector
	{
	public:
		Vector() = default;
		~Vector() = default;
		Vector(Vector&&) = default;
		Vector& operator = (Vector&&) = default;
		Vector(const Vector&) = default;
		Vector& operator = (const Vector&) = default;

		Vector(int length_)
			: length(length_)
		{
		}

		Vector(int length_, vector<int>& indices_, Fvec& values_)
			:length(length_)
		{
			indices.swap(indices_);
			values.swap(values_);
		}

		void Init(int length_, vector<int>& indices_, Fvec& values_)
		{
			length = length_;
			indices.swap(indices_);
			values.swap(values_);
		}

		void Swap(Vector& other)
		{
			length = other.length;
			indices.swap(other.indices);
			values.swap(other.values);
		}

		//to a densnse format from values
		Vector(Fvec& values_)
		{
			ToDense(values_);
		}

		void Init(Fvec& values_)
		{
			ToDense(values_);
		}

		void ToDense(Fvec& values_)
		{
			values.swap(values_);
			length = values.size();
			indices.clear();
		}

		void ToDense()
		{
			Fvec vec(length, 0);
			for (size_t i = 0; i < indices.size(); i++)
			{
				vec[indices[i]] = values[i];
			}
			indices.clear();
			values.swap(vec);
		}

		//do not check if dense // _indices empty
		void ToSparse()
		{
			Fvec vec;
			for (size_t i = 0; i < values.size(); i++)
			{
				if (values[i])
				{
					indices.push_back(i);
					vec.push_back(values[i]);
				}
			}
			values.swap(vec);
		}

		void MakeDense()
		{
			if (IsSparse())
			{
				ToDense();
			}
		}

		void MakeSparse()
		{
			if (IsDense())
			{
				ToSparse();
			}
		}

		void Add(Float value)
		{
			values.push_back(value);
		}

		void Add(int index, Float value)
		{
			if (value)
			{
				indices.push_back(index);
				values.push_back(value);
			}
		}

		void PrepareDense()
		{
			values.reserve(length);
		}

		void Sparsify()
		{
			int nonZeroNum = 0;
			for (auto item : values)
			{
				if (item != 0)
				{
					nonZeroNum++;
				}
			}
			//@TODO 检查特征全是0的情况
			if (nonZeroNum < (uint64)(length * maxSparsity))
			{
				ToSparse();
			}
		}

		void Densify()
		{
			if (Count() >= (uint64)(length * maxSparsity))
			{
				ToDense();
			}
		}

		Float operator[](int i) const
		{
#ifndef NDEBUG
			if (i < 0 || i >= length)
				THROW((format("Index %d out of range in Vector of length %d") % i % length).str());
#endif 
			if (IsDense())
			{
				return values[i];
			}
			else
			{
				auto iter = std::lower_bound(indices.begin(), indices.end(), i);
				if (iter == indices.end() || *iter != i)
				{
					return 0;
				}
				return values[iter - indices.begin()];
			}
		}

		Float& operator[](int i)
		{
#ifndef NDEBUG
			if (i < 0 || i >= length)
				THROW((format("Index %d out of range in Vector of length %d") % i % length).str());
#endif 
			if (IsDense())
			{
				return values[i];
			}
			else
			{
				auto iter = std::lower_bound(indices.begin(), indices.end(), i);
#ifndef NDEBUG
				if (iter == indices.end() || *iter != i)
					THROW((format("In sparse vector could not find the index %d") % i).str());
#endif 
				return values[iter - indices.begin()];
			}
		}

		/// Applies the given ValueVisitor to every element of the vector, in order of index.  (Zeros of sparse vectors will not be included.)
		template<typename ValueVistor>
		void ForEach(ValueVistor visitor) const
		{
			if (IsDense())
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(i, values[i]);
				}
			}
			else
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(indices[i], values[i]);
				}
			}
		}

		template<typename ValueVistor>
		void ForEachAll(ValueVistor visitor) const
		{
			if (IsDense())
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(i, values[i]);
				}
			}
			else
			{
				size_t j = 0;
				for (size_t i = 0; i < values.size(); i++)
				{
					while (j < indices[i])
					{
						visitor(j++, 0);
					}
					visitor(j++, values[i]);
				}
			}
		}

		template<typename ValueVistor>
		void ForEachAllSparse(ValueVistor visitor) const
		{
			size_t j = 0;
			for (size_t i = 0; i < values.size(); i++)
			{
				while (j < indices[i])
				{
					visitor(j++, 0);
				}
				visitor(j++, values[i]);
			}
		}


		template<typename ValueVistor>
		void ForEach(ValueVistor visitor)
		{
			if (IsDense())
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(i, ref(values[i]));
				}
			}
			else
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(indices[i], ref(values[i]));
				}
			}
		}

		template<typename ValueVistor>
		void ForEachDense(ValueVistor visitor) const
		{
			for (size_t i = 0; i < values.size(); i++)
			{
				visitor(i, values[i]);
			}
		}
		template<typename ValueVistor>
		void ForEachDense(ValueVistor visitor)
		{
			for (size_t i = 0; i < values.size(); i++)
			{
				visitor(i, ref(values[i]));
			}
		}

		template<typename ValueVistor>
		void ForEachSparse(ValueVistor visitor) const
		{
			for (size_t i = 0; i < values.size(); i++)
			{
				visitor(indices[i], values[i]);
			}
		}

		template<typename ValueVistor>
		void ForEachSparse(ValueVistor visitor)
		{
			for (size_t i = 0; i < values.size(); i++)
			{
				visitor(indices[i], ref(values[i]));
			}
		}

		//注意自己保证稀疏格式value不是0 一般用于print 只读 还ok
		template<typename ValueVistor>
		void ForEachNonZero(ValueVistor visitor) const
		{
			if (IsDense())
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					if (values[i])
					{
						visitor(i, values[i]);
					}
				}
			}
			else
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(indices[i], values[i]);
				}
			}
		}

		template<typename ValueVistor>
		void ForEachNonZero(ValueVistor visitor)
		{
			if (IsDense())
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					if (values[i])
					{
						visitor(i, ref(values[i]));
					}
				}
			}
			else
			{
				for (size_t i = 0; i < values.size(); i++)
				{
					visitor(indices[i], ref(values[i]));
				}
			}
		}

	public:
		/// True if the Vector is using sparse representation. 也有可能是空feature
		bool IsDense() const
		{
			return indices.empty();
		}

		bool IsSparse() const
		{
			return !indices.empty();
		}
		/// Gets a int value representing the dimensionality of the vector.
		int Length() const
		{
			return length;
		}

		void SetLength(int length_)
		{
			length = length_;
		}

		/// no real content stored? 因为没有支持binary 所以value为空 就表示没有数据
		bool Empty() const
		{
			return values.empty();
		}

		/// Gets the number of explicitly represented values in the vector.
		int Count() const
		{
			return values.size();
		}

		const vector<int>& Indices() const
		{
			return indices;
		}

		const Fvec& Values() const
		{
			return values;
		}

		vector<int>& Indices()
		{
			return indices;
		}

		Fvec& Values()
		{
			return values;
		}

		int Index(int index) const
		{
			return indices[index];
		}

		int Index(int index)
		{
			return indices[index];
		}

		Float Value(int index) const
		{
			return values[index];
		}

		Float& Value(int index)
		{
			return values[index];
		}

		void CheckInvariants()
		{
			if (IsDense())
			{
				CHECK_EQ(values.size(), length);
			}
			else
			{
				CHECK_EQ(values.size(), indices.size());
				//@TODO 检查所有indice是在合理范围？ 排序？
			}
		}
		/// <summary>
		/// Multiples the Vector by a real value
		/// </summary>
		/// <param name="d">Value to multiply vector with</param>
		void ScaleBy(Float d)
		{
			if (d == 1.0)
				return;

			if (d == 0)
			{
				if (!keepDense)
				{
					values.clear();
					indices.clear();
				}
				else
				{
					for (int i = 0; i < values.length; i++)
						values[i] = 0;
				}
			}
			else
			{
				for (int i = 0; i < values.length; i++)
					values[i] *= d;
			}
		}

		friend Float dot(const Vector& l, const Vector& r);

	public:
		vector<int> indices; //不使用Node(index,value)更加灵活 同时可以允许一项为空
		Fvec values;
		int length = 0;
		Float maxSparsity = 0.5;
		bool keepDense = false;
	};

	Float dot(const Vector& a, const Vector& b)
	{
		if (a.indices.begin() == b.indices.begin())
		{
			if (a.Length() != b.Length())
			{
				THROW("Vectors must have the same dimensionality.");
			}
			Float res = 0;
			for (size_t i = 0; i < a.values.size(); i++)
			{
				res += a.values[i] * b.values[i];
			}
			return res;
		}

		Float result = 0;

		if (b.IsDense())
		{
			for (size_t i = 0; i < a.indices.size(); i++)
				result += a.values[i] * b.values[a.indices[i]];
		}
		else if (a.IsDense())
		{
			for (size_t i = 0; i < b.indices.size(); i++)
				result += a.values[b.indices[i]] * b.values[i];
		}
		else
		{ // both sparse
			size_t aI = 0, bI = 0;
			while (aI < a.indices.size() && bI < b.indices.size())
			{
				switch (compare(a.indices[aI],b. indices[bI]))
				{
				case 0:
					result += a.Value(aI++) * b.Value(bI++);
					break;
				case -1:
					aI++;
					break;
				case 1:
					bI++;
					break;
				default:
					break;
				}
			}
		}

		return result;
	}
}  //----end of namespace gezi

#endif  //----end of NUMERIC__VECTOR__VECTOR_H_
