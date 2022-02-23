#include <iostream>

class V
{
public:
	virtual void Print()
	{
		std::cout << "V\n";
	}
};

class VV : public V
{
public:
	virtual void Print()
	{
		std::cout << "V-V\n";
	}
};

class VVV : public VV
{
public:
	virtual void Print()
	{
		std::cout << "V-V-V\n";
	}
};

class VVN : public VV
{
public:
	void Print()
	{
		std::cout << "V-V-N\n";
	}
};

class VN : public V
{
public:
	void Print()
	{
		std::cout << "V-N\n";
	}
};

class VNV :public VN
{
public:
	virtual void Print()
	{
		std::cout << "V-N-V\n";
	}
};

class VNN : public VN
{
public:
	void Print()
	{
		std::cout << "V-N-N\n";
	}
};

/*//---------------------------------------------------------------------//*/

class N
{
public:
	void Print()
	{
		std::cout << "N\n";
	}
};

class NN : public N
{
public:
	void Print()
	{
		std::cout << "N-N\n";
	}
};

class NNN : public NN
{
public:
	void Print()
	{
		std::cout << "N-N-N\n";
	}
};

class NNV : public NN
{
public:
	virtual void Print()
	{
		std::cout << "N-N-V\n";
	}
};

class NV : public N
{
public:
	virtual void Print()
	{
		std::cout << "N-V\n";
	}
};

class NVN : public NV
{
public:
	void Print()
	{
		std::cout << "N-V-N\n";
	}
};

class NVV : public NV
{
public:
	virtual void Print()
	{
		std::cout << "N-V-V\n";
	}
};


int main()
{
	V v, *pv;
	VV vv, *pvv;
	VVV vvv;
	VVN vvn;
	VN vn, *pvn;
	VNV vnv;
	VNN vnn;

	N n, *pn;
	NN nn, *pnn;
	NNN nnn;
	NNV nnv;
	NV nv, *pnv;
	NVN nvn;
	NVV nvv;

	std::cout << "\n\npv Print check\n";
	pv = &v; pv->Print();
	pv = &vv; pv->Print();
	pv = &vvv; pv->Print();
	pv = &vvn; pv->Print();
	pv = &vn; pv->Print();
	pv = &vnv; pv->Print();
	pv = &vnn; pv->Print();

	std::cout << "\n\npvv Print check\n";
	//pvv = &v; pvv->Print();
	pvv = &vv; pvv->Print();
	pvv = &vvv; pvv->Print();
	pvv = &vvn; pvv->Print();
	//pvv = &vn; pvv->Print();
	//pvv = &vnv; pvv->Print();
	//pvv = &vnn; pvv->Print();

	std::cout << "\n\npvn Print check\n";
	//pvn = &v; pvn->Print();
	//pvn = &vv; pvn->Print();
	//pvn = &vvv; pvn->Print();
	//pvn = &vvn; pvn->Print();
	pvn = &vn; pvn->Print();
	pvn = &vnv; pvn->Print();
	pvn = &vnn; pvn->Print();

/*//----------------------------------//*/

	std::cout << "\n\npn Print check\n";
	pn = &n; pn->Print();
	pn = &nv; pn->Print();
	pn = &nvv; pn->Print();
	pn = &nvn; pn->Print();
	pn = &nn; pn->Print();
	pn = &nnv; pn->Print();
	pn = &nnn; pn->Print();

	std::cout << "\n\npnv Print check\n";
	//pnv = &n; pnv->Print();
	pnv = &nv; pnv->Print();
	pnv = &nvv; pnv->Print();
	pnv = &nvn; pnv->Print();
	//pnv = &nn; pnv->Print();
	//pnv = &nnv; pnv->Print();
	//pnv = &nnn; pnv->Print();

	std::cout << "\n\npnn Print check\n";
	//pnn = &n; pnn->Print();
	//pnn = &nv; pnn->Print();
	//pnn = &nvv; pnn->Print();
	//pnn = &nvn; pnn->Print();
	pnn = &nn; pnn->Print();
	pnn = &nnv; pnn->Print();
	pnn = &nnn; pnn->Print();

	getchar();
}