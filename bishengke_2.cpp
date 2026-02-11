#include <cstdio>
class IMotor
{
	public:
	   	virtual void SetOutput(int force)=0;
	   	virtual int GetSpeed()=0;
	   	virtual void Update()=0;
	   	virtual ~IMotor(){}
};
class DJIMotor:public IMotor
{
	public:
	void SetOutput(int force) override
	{
		printf("[CAN BUS]ID: 0x201, Send Current: %d\n",force);
	}
	int GetSpeed() override
	{
		return 1000;
	}
	void Update() override
	{
		
	}
};
class SimMotor:public IMotor
{
	public:
		SimMotor():velocity_(0),F(0),f(10)
		{
			
		}
		void SetOutput(int force) override
		{
			F=force;
		}
		int GetSpeed() override
		{
			return velocity_;
		}
		void Update() override
		{
			velocity_=velocity_+(F-f);
			if(velocity_<0)
			{
				velocity_=0;
			}
		}
	private:
		int velocity_;
		int F;
		int f;
};
void TestMotor(IMotor* m)
{
	int v;
	m->SetOutput(10000);
	m->Update();
	v=m->GetSpeed();
	printf("speed=%d\n",v);
}
int main()
{
	IMotor* m_1=new DJIMotor();
	TestMotor(m_1);
	IMotor* m_2=new SimMotor();
	TestMotor(m_2);
	delete m_1;
	delete m_2;
}
