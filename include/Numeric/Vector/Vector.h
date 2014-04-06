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

		void Swap(Vector& other)
		{
			_length = other._length;
			_indices.swap(other._indices);
			_values.swap(other._values);
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

		void Sparsify()
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
			if (nonZeroNum < (uint64) (_length * _maxSparsity))
			{
				ToSparse();
			}
		}

		void Densify()
		{
			if (Count() >= (uint64) (_length * _maxSparsity))
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
		void ForEachAll(ValueVistor visitor) const
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
				size_t j = 0;
				for (size_t i = 0; i < _values.size(); i++)
				{
					while (j < _indices[i])
					{
						visitor(j++, 0);
					}
					visitor(j++, _values[i]);
				}
			}
		}

		template<typename ValueVistor>
		void ForEachAllSparse(ValueVistor visitor) const
		{
			size_t j = 0;
			for (size_t i = 0; i < _values.size(); i++)
			{
				while (j < _indices[i])
				{
					visitor(j++, 0);
				}
				visitor(j++, _values[i]);
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

		template<typename ValueVistor>
		void ForEachDense(ValueVistor visitor) const
		{
			for (size_t i = 0; i < _values.size(); i++)
			{
				visitor(i, _values[i]);
			}
		}
		template<typename ValueVistor>
		void ForEachDense(ValueVistor visitor)
		{
			for (size_t i = 0; i < _values.size(); i++)
			{
				visitor(i, ref(_values[i]));
			}
		}

		template<typename ValueVistor>
		void ForEachSparse(ValueVistor visitor) const
		{
			for (size_t i = 0; i < _values.size(); i++)
			{
				visitor(_indices[i], _values[i]);
			}
		}

		template<typename ValueVistor>
		void ForEachSparse(ValueVistor visitor)
		{
			for (size_t i = 0; i < _values.size(); i++)
			{
				visitor(_indices[i], ref(_values[i]));
			}
		}

		//注意自己保证稀疏格式value不是0 一般用于print 只读 还ok
		template<typename ValueVistor>
		void ForEachNonZero(ValueVistor visitor) const
		{
			if (IsDense())
			{
				for (size_t i = 0; i < _values.size(); i++)
				{
					if (_values[i])
					{
						visitor(i, _values[i]);
					}
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
		void ForEachNonZero(ValueVistor visitor)
		{
			if (IsDense())
			{
				for (size_t i = 0; i < _values.size(); i++)
				{
					if (_values[i])
					{
						visitor(i, ref(_values[i]));
					}
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
		/// True if the Vector is using sparse representation. 也有可能是空feature
		bool IsDense() const
		{
			return _indices.empty();
		}

		bool IsSparse() const
		{
			return !_indices.empty();
		}
		/// Gets a int value representing the dimensionality of the vector.
		int Length() const
		{
			return _length;
		}

		void SetLength(int length)
		{
			_length = length;
		}

		/// no real content stored? 因为没有支持binary 所以value为空 就表示没有数据
		bool Empty() const
		{
			return _values.empty();
		}

		/// Gets the number of explicitly represented values in the vector.
		int Count() const
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

		int IndexAt(int index) const
		{
			return _indices[index];
		}

		int IndexAt(int index)
		{
			return _indices[index];
		}

		Float ValueAt(int index) const
		{
			return _values[index];
		}

		Float& ValueAt(int index)
		{
			return _values[index];
		}

		void CheckInvariants()
		{
			if (IsDense())
			{
				CHECK_EQ(_values.size(), _length);
			}
			else
			{
				CHECK_EQ(_values.size(), _indices.size());
				//@TODO 检查所有indice是在合理范围？ 排序？
			}
		}
	protected:
	private:
		vector<int> _indices; //不使用Node(index,value)更加灵活 同时可以允许一项为空
		vector<Float> _values;
		int _length = 0;
		Float _maxSparsity = 0.5;
	};

}  //----end of namespace gezi

#endif  //----end of NUMERIC__VECTOR__VECTOR_H_
