#pragma once
namespace stack {
	template <typename type>
	class Stack
	{
		type * data;
		size_t size, top;
	public:
		Stack()
		{
			size = 1, top = 0;
			data = new type[size];
			data[0] = 0;
		}
		size_t getTop() const
		{
			return top;
		}
		size_t getSize() const
		{
			return size;
		}
		void push(const type & value)
		{
			if (top + 1 >= size)
			{
				size *= 2;
				data = (type*)realloc(data, size * sizeof(type));
			}
			data[++top] = value;
		}
		type & pop()
		{
			return data[top--];
		}
		type & peek() {
			return data[top];
		}
		~Stack()
		{
			delete[] data;
		}
	};
}

