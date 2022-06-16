#pragma once
#include <filesystem>
#include "PlainLogger.h"
#include "Exceptions.h"

class SequentialStruct
{
protected:
	size_t counter_ = 0;
public:
	virtual void SetValue(const std::string& Value) = 0;
};

class SequentialVectorBase : public SequentialStruct
{
public:
	virtual void SetSize(size_t Size) = 0;
	virtual void New() = 0;
};

template<typename T>
class SequentialVector : public SequentialVectorBase, public std::vector<T>
{
public:
	void SetSize(size_t Size) override
	{
		std::vector<T>::reserve(Size);
	}

	void New() override
	{
		std::vector<T>::push_back({});
	}

	void SetValue(const std::string& Value) override
	{
		std::vector<T>::back().SetValue(Value);
	}
};

class MatPowerCase
{
protected:
	bool Silent_ = false;
public:
	CPlainLogger& logger_;

	struct BusData : public SequentialStruct
	{
		long Id;			// 1 
		long Type;			// 2 { PQ - 1, PV - 2, Slack - 3, Isolated - 4 }
		double Pn;			// 3
		double Qn;			// 4
		double Gsh;			// 5
		double Bsh;			// 6
		long AreaId;		// 7
		double V;			// 8
		double Delta;		// 9
		std::string Name;
		double Unom;		// 10
		long LossAreaId;	// 11
		double Vmin;		// 12
		double Vmax;		// 13

		void SetValue(const std::string& Value) override
		{
			switch (++counter_)
			{
			case 1:		Id = std::stol(Value); break;
			case 2:		Type = std::stol(Value); break;
			case 3:		Pn = std::stod(Value); break;
			case 4:		Qn = std::stod(Value); break;
			case 5:		Gsh = std::stod(Value); break;
			case 6:		Bsh = std::stod(Value); break;
			case 7:		AreaId = std::stol(Value); break;
			case 8:		V = std::stod(Value); break;
			case 9:		Delta = std::stod(Value); break;
			case 10:	Unom = std::stod(Value); break;
			case 11:	LossAreaId = std::stol(Value); break;
			case 12:	Vmin = std::stod(Value); break;
			case 13:	Vmax = std::stod(Value); break;
			default:
				break;
				throw CException("BusData::SetValue - counter is out of range");
			}
		}
	};

	struct BranchData : public SequentialStruct
	{
		long IdHead;	// 1   f, from bus number
		long IdTail;	// 2   t, to bus number
		double r;		// 3   r, resistance(p.u.)
		double x;		// 4   x, reactance(p.u.)
		double b;		// 5   b, total line charging susceptance(p.u.)
		double rateA;	// 6   rateA, MVA rating A(long term rating)
		double rateB;	// 7   rateB, MVA rating B(short term rating)
		double rateC;	// 8   rateC, MVA rating C(emergency rating)
		double ktr;		// 9   ratio, transformer off nominal turns ratio(= 0 for lines) (taps at 'from' bus, impedance at 'to' bus, i.e. if r = x = 0, then ratio = Vf / Vt)
		double kti;		// 10  angle, transformer phase shift angle(degrees), positive = > delay
		long State;		// 11  initial branch status, 1 - in service, 0 - out of service
		double Dmin;	// 12  minimum angle difference, angle(Vf) - angle(Vt) (degrees)
		double Dmax; 	// 13  maximum angle difference, angle(Vf) - angle(Vt) (degrees) (The voltage angle difference is taken to be unbounded below
						// if ANGMIN < -360 and unbounded above if ANGMAX > 360.
						// If both parameters are zero, it is unconstrained.)

		void SetValue(const std::string& Value) override
		{
			switch (++counter_)
			{
			case 1:		IdHead = std::stol(Value); break;
			case 2:		IdTail = std::stol(Value); break;
			case 3:		r = std::stod(Value); break;
			case 4:		x = std::stod(Value); break;
			case 5:		b = std::stod(Value); break;
			case 6:		rateA = std::stod(Value); break;
			case 7:		rateB = std::stod(Value); break;
			case 8:		rateC = std::stod(Value); break;
			case 9:		ktr = std::stod(Value); break;
			case 10:	kti = std::stod(Value); break;
			case 11:	State = std::stol(Value); break;
			case 12:	Dmin = std::stod(Value); break;
			case 13:	Dmax = std::stod(Value); break;
			default:
				break;
				throw CException("BranchData::SetValue - counter is out of range");
			}
		}
	};

	struct GeneratorData : public SequentialStruct
	{
		long Id;		// 1   bus number
		double Pg;		// 2   Pg, real power output(MW)
		double Qg;		// 3   Qg, reactive power output(MVAr)
		double Qmax;	// 4   Qmax, maximum reactive power output(MVAr)
		double Qmin; 	// 5   Qmin, minimum reactive power output(MVAr)
		double Vg;		// 6   Vg, voltage magnitude setpoint(p.u.)
		double Sbase;	// 7   mBase, total MVA base of this machine, defaults to baseMVA
		long State;		// 8   status, > 0 - machine in service <= 0 - machine out of service
		double Pmax;	// 9   Pmax, maximum real power output(MW)
		double Pmin;	// 10  Pmin, minimum real power output(MW)
		double Pc1;		// 11  Pc1, lower real power output of PQ capability curve(MW)
		double Pc2;		// 12  Pc2, upper real power output of PQ capability curve(MW)
		double Qc1min;	// 13  Qc1min, minimum reactive power output at Pc1(MVAr)
		double Qc1max;	// 14  Qc1max, maximum reactive power output at Pc1(MVAr)
		double Qc2min;	// 15  Qc2min, minimum reactive power output at Pc2(MVAr)
		double Qc2max;	// 16  Qc2max, maximum reactive power output at Pc2(MVAr)
		double ramp;	// 17  ramp rate for load following / AGC(MW / min)
		double ramp10;	// 18  ramp rate for 10 minute reserves(MW)
		double ramp30;	// 19  ramp rate for 30 minute reserves(MW)
		double rampQ;	// 20  ramp rate for reactive power(2 sec timescale) (MVAr / min)
		double APF;		// 21  APF, area participation factor

		void SetValue(const std::string& Value) override
		{
			switch (++counter_)
			{
			case 1:		Id = std::stol(Value); break;
			case 2:		Pg = std::stod(Value); break;
			case 3:		Qg = std::stod(Value); break;
			case 4:		Qmax = std::stod(Value); break;
			case 5:		Qmin = std::stod(Value); break;
			case 6:		Vg = std::stod(Value); break;
			case 7:		Sbase = std::stod(Value); break;
			case 8:		State = std::stol(Value); break;
			case 9:		Pmax = std::stod(Value); break;
			case 10:	Pmin = std::stod(Value); break;
			case 11:	Pc1 = std::stod(Value); break;
			case 12:	Pc2 = std::stod(Value); break;
			case 13:	Qc1min = std::stod(Value); break;
			case 14:	Qc1max = std::stod(Value); break;
			case 15:	Qc2min = std::stod(Value); break;
			case 16:	Qc2max = std::stod(Value); break;
			case 17:	ramp = std::stod(Value); break;
			case 18:	ramp10 = std::stod(Value); break;
			case 19:	ramp30 = std::stod(Value); break;
			case 20:	rampQ = std::stod(Value); break;
			case 21:	APF = std::stod(Value); break;
			default:
				break;
				throw CException("GeneratorData::SetValue - counter is out of range");
			}
		}
	};

	struct AreaData : public SequentialStruct
	{
		long Id = 0;

		AreaData(long Area) : Id(Area) {}
		AreaData()  {}

		void SetValue(const std::string& Value) override
		{
			switch (++counter_)
			{
			case 1:		Id = std::stol(Value); break;
			default:
				throw CException("AreaData::SetValue - counter is out of range");
			}
		}

	};

	double BaseMVA_ = 100.0;

	MatPowerCase(CPlainLogger& logger);
	void Import(const std::filesystem::path& path);
	void Export(const std::filesystem::path& path);
	bool Silent() const { return Silent_; }
	void SetSilent(bool Silent) { Silent_ = Silent; }

	class SequentialBusNames : public SequentialVectorBase
	{
	private:
		std::vector<BusData>& vec_;
		size_t index_ = 0;
	public:
		SequentialBusNames(std::vector<BusData>& vec) : vec_(vec) {}
		void SetSize(size_t Size) override {}

		void New() override 
		{
			index_++;
		}

		void SetValue(const std::string& Value) override
		{
			vec_[index_ - 1].Name = Value;
		}
	};

	SequentialVector<BusData> buses;
	SequentialVector<GeneratorData> generators;
	SequentialVector<BranchData> branches;
	SequentialVector<AreaData> areas;
	SequentialBusNames busnames;

	static constexpr const char* cszFileCannotBeOpened = "File {} cannot be opened";
};