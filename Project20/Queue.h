#pragma once
#include <initializer_list>
namespace quene {
	template <class T>
	class Quene
	{
	public:
		T * data;
		size_t size;
		int first_element = 0;
		Quene(int size)
		{
			data = new T[size];
		}
		~Quene()
		{
			delete[] data;
		}
		Quene(std::initializer_list<T> & elements)
		{
			for (auto & element : elements) {
				this->enquene(element);
			}
			first_element = elements.size();
		}
		void enquene(const T & element)
		{
			if (nullptr == data)
			{
				data = new T[++size];
				data[0] = element;
			}
			else
			{
				data = (T*)realloc(data, ++size * sizeof(T));
				data[size - 1] = element;
			}
		}
		void dequene()
		{
			if (size == first_element)
			{
				std::cout << data[0] << std::endl;
			}
			else
				std::cout << data[0 + (size - first_element)] << std::endl;
		}
		size_t count() const
		{
			return size;
		}
		void clear()
		{
			delete[] data;
		}
		T operator +(T & other)
		{
			T res;
			res.size = this->size + other.size;
			res.data = new char[res.size];
			int i = 0;
			for (; i < this->size; ++i)
			{
				res.data[i] = this->data[i];
			}
			for (i = this->size; i < res.size; ++i)
			{
				res.data[i] = other.data[i - this->size];
			}
			return res;
		}
		size_t operator[](int i)
		{
			if (i < size)
			{
				return data[i];
			}
		}

		T operator -(T & m)
		{
			T res;
			for (int i = 0; i < data.size() - 1; ++i)
			{
				res.data[i];
			}
			return res;
		}

	};
}

