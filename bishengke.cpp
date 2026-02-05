template<typename T>
class LimitValue
{
	public:
		LimitValue(T current,T min,T max):current_value(current),min_value(min),max_value(max)
		{
			if(max_value<min_value)
        	{
        		T index=max_value;
        		max_value=min_value;
        		min_value=index;
			}
			current_value=Calculate(current_value);
		}
		 T Calculate(T t)
        {
        	if(t<min_value)
        	{
        		t=min_value;
			}
			else if(t>max_value)
			{
				t=max_value;
			}
            return t;
        }
		LimitValue& operator=(T t)
		{
			current_value=Calculate(t);
			return *this;
		}
		LimitValue& operator+=(T t)
		{
			current_value=Calculate(current_value+t);
			return *this;
		}
		T val() const
		{
			return current_value;
		}
	private:
		T current_value;
		T min_value;
		T max_value;
}
