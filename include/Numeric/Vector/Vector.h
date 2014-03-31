/**
 *  ==============================================================================
 *
 *          \file   Numeric/Vector/Vector.h
 *
 *        \author   chenghuige
 *
 *          \date   2014-03-26 10:46:03.965585
 *
 *  \Description:  支持读写，dense and sparse
 *  ==============================================================================
 */

#ifndef NUMERIC__VECTOR__VECTOR_H_
#define NUMERIC__VECTOR__VECTOR_H_

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

		Vector(int length)
			: _length(length)
		{
		}

		Vector(int length, vector<int>& indices, vector<Float>& values)
			:_length(length)
		{
			_indices.swap(indices);
			_values.swap(values);
		}

		void Create(int length, vector<int>& indices, vector<Float>& values)
		{
			_length = length;
			_indices.swap(indices);
			_values.swap(values);
		}

		//to a densnse format from values
		Vector(vector<Float>& values)
		{
			ToDense(values);
		}

		void ToDense(vector<Float>& values)
		{
			_values.swap(values);
			_length = _values.size();
			_indices.clear();
		}

		void ToDense()
		{
			vector<Float> vec(_length, 0);
			for (size_t i = 0; i < _indices.size(); i++)
			{
				vec[_indices[i]] = _values[i];
			}
			_indices.clear();
			_values.swap(vec);
		}

		//do not check if dense // _indices empty
		void ToSparse()
		{
			vector<Float> vec;
			for (size_t i = 0; i < _values.size(); i++)
			{
				if (_values[i])
				{
					_indices.push_back(i);
					vec.push_back(_values[i]);
				}
			}
			_values.swap(vec);
		}

		void Add(Float value)
		{		
			_values.push_back(value);
		}

		void Add(int index, Float value)
		{
			if (value)
			{
				_indices.push_back(index);
				_values.push_back(value);
			}
		}

		void PrepareDense()
		{
			_values.reserve(_length);
		}

		void TrySparse()
		{
			int nonZeroNum = 0;
			for (auto item : _values)
			{
				if (item != 0)
				{
					nonZeroNum++;
				}
			}
			//@TODO 检查特征全是0的情况
			if (nonZeroNum < _length / 2)
			{
				ToSparse();
			}
		}

		void TryDense()
		{
			if (Count() >= _length / 2)
			{
				ToDense();
			}
		}

		Float Value(int i) const
		{
			return _values[i];
		}
		
		Float& Value(int i)
		{
			return _values[i];
		}

		Float operator[](int i) const
		{
#ifndef NDEBUG
			if (i < 0 || i >= _length)
				THROW((format("Index %d out of range in Vector of length %d") % i % _length).str());
#endif 
			if (IsDense())
			{
				return _values[i];
			}
			else
			{
				auto iter = std::lower_bound(_indices.begin(), _indices.end(), i);
				if (iter == _indices.end() || *iter != i)
				{
					return 0;
				}
				return _values[iter - _indices.begin()];
			}
		}

		Float& operator[](int i)
		{
#ifndef NDEBUG
			if (i < 0 || i >= _length)
				THROW((format("Index %d out of range in Vector of length %d") % i % _length).str());
#endif 
			if (IsDense())
			{
				return _values[i];
			}
			else
			{
				auto iter = std::lower_bound(_indices.begin(), _indices.end(), i);
#ifndef NDEBUG
				if (iter == _indices.end() || *iter != i)
					THROW((format("In sparse vector could not find the index %d") % i).str());
#endif 
				return _values[iter - _indices.begin()];
			}
		}

		/// Applies the given ValueVisitor to every element of the vector, in order of index.  (Zeros of sparse vectors will not be included.)
		template<typename ValueVistor>
		void ForEach(ValueVistor visitor) const
		{
			if (IsDense())
			{
				for (size_t i = 0; i < _values.size(); i++)
				{
					visitor(i, _values[i]);
				}
			}
			else
			{
				for (size_t i = 0; i < _values.size(); i++)
				{
					visitor(_indices[i], _values[i]);
				}
			}
		}

		template<typename ValueVistor>
		void ForEach(ValueVistor visitor)
		{
			if (IsDense())
			{
				for (size_t i = 0; i < _values.size(); i++)
				{
					visitor(i, ref(_values[i]));
				}
			}
			else
			{
				for (size_t i = 0; i < _values.size(); i++)
				{
					visitor(_indices[i], ref(_values[i]));
				}
			}
		}
	public:
		/// True if the Vector is using sparse representation.
		inline bool IsDense() const
		{
			return _indices.empty();
		}

		inline bool IsSparse() const
		{
			return !_indices.empty();
		}
		/// Gets a int value representing the dimensionality of the vector.
		inline	int Length() const
		{
			return _length;
		}

		/// Gets the number of explicitly represented values in the vector.
		inline int Count() const
		{
			return _values.size();
		}

		const vector<int>& Indices() const
		{
			return _indices;
		}

		const vector<Float>& Values() const
		{
			return _values;
		}

		vector<int>& Indices()
		{
			return _indices;
		}

		vector<Float>& Values()
		{
			return _values;
		}
	protected:
	private:
		vector<int> _indices; //不使用Node(index,value)更加灵活 同时可以允许一项为空
		vector<Float> _values;
		int _length = 0;
	};

}  //----end of namespace gezi

#endif  //----end of NUMERIC__VECTOR__VECTOR_H_
