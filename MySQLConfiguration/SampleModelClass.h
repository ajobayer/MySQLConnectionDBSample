#if !defined SampleModelClass_H
#define SampleModelClass_H

class SampleModelClass
{
private:
	int		mAutoIncrimentID;
	int		mSymbolID;
	double	mTickValueChangePercent;
	int		mTickValueCount;
	int		mPipsValue;

public:
	SampleModelClass(void);
	~SampleModelClass(void);

public:
	int getAutoIncrimentID(){return mAutoIncrimentID;};
	void setAutoIncrimentID(int aAutoIncrimentID){mAutoIncrimentID=aAutoIncrimentID;};

	int getSymbolID(){return mSymbolID;};
	void setSymbolID(int aSymbolID){mSymbolID=aSymbolID;};

	double getTickValueChangePercent(){return mTickValueChangePercent;};
	void setTickValueChangePercent(double aTickValueChangePercent){mTickValueChangePercent=aTickValueChangePercent;};

	int getTickValueCount(){return mTickValueCount;};
	void setTickValueCount(int aTickValueCount){mTickValueCount=aTickValueCount;};

	int getPipsValue(){return mPipsValue;};
	void setPipsValue(int aPipsValue){mPipsValue=aPipsValue;};
};

#endif