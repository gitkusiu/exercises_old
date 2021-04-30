#include<memory>
#include<iostream>

void f(const std::unique_ptr<int> p)
{
	std::cout << "p.get() =          " << p.get() << std::endl;
	std::cout << "p.get() == nullptr " << (p.get() == nullptr) << std::endl;
	if(p.get() != nullptr)
	{
		std::cout << "*p     =       " << *p << std::endl;
	}
}

int main()
{
	{

	std::cout << "-------------------------------------------------- " << std::endl;
	std::unique_ptr<int> p1(std::make_unique<int>(1));
	std::cout << "std::unique_ptr<int> p1(std::make_unique<int>(1));" << std::endl;	
	       std::cout << "p1.get() = " << p1.get() << std::endl;
	if(p1) std::cout << "*p1      = " << *p1 << std::endl;

	std::unique_ptr<int> p2(std::move(p1));
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- "  << std::endl;
	std::cout << "std::unique_ptr<int> p2(std::move(p1));" << std::endl;
	std::cout << "p1.get() =          " << p1.get() << std::endl;
	std::cout << "p1.get() == nullptr " << (p1.get() == nullptr) << std::endl;
	//std::cout << "*p1 == std::null_ptr     = " << *p1 == std::null << std::endl;
	std::cout << "p2.get() =          " << p2.get() << std::endl;
	std::cout << "p2.get() == nullptr " << (p2.get() == nullptr) << std::endl;
	std::cout << "*p2      =          " << *p2 << std::endl;

	p1 = std::move(p2);
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "p1 = std::move(p2);" << std::endl;
	std::cout << "p1.get() = " << p1.get() << std::endl;
	std::cout << "*p1      = " << *p1 << std::endl;
	std::cout << "p2.get() =          " << p2.get() << std::endl;
	std::cout << "p2.get() == nullptr " << (p2.get() == nullptr) << std::endl;
	//std::cout << "*p2      =          " << *p2 << std::endl;

	int * p = p1.release();
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "int * p = p1.release();" << std::endl;
	std::cout << "p1.get() == nullptr " << (p1.get() == nullptr) << std::endl;
	std::cout << "p == nullptr " << (p == nullptr) << std::endl;
	std::cout << "p        = " << p << std::endl;
	std::cout << "*p       = " << *p << std::endl;



	p1 = std::make_unique<int>(10);
	p2 = std::make_unique<int>(20);
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "p1 = std::make_unique<int>(10);" << std::endl;
	std::cout << "p2 = std::make_unique<int>(20);" << std::endl;
	std::cout << " p1.get() = " <<  p1.get() << std::endl;
	std::cout << "*p1       = " << *p1 << std::endl;
	std::cout << " p2.get() = " <<  p2.get() << std::endl;
	std::cout << "*p2       = " << *p2 << std::endl;

	p1.swap(p2);
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "p1.swap(p2);" << std::endl;
	std::cout << " p1.get() = " <<  p1.get() << std::endl;
	std::cout << "*p1       = " << *p1 << std::endl;
	std::cout << " p2.get() = " <<  p2.get() << std::endl;
	std::cout << "*p2       = " << *p2 << std::endl;	


	std::unique_ptr<int> p3(std::move(p));
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "std::unique_ptr<int> p3(std::move(p));" << std::endl;
	std::cout << " p3.get() = " <<  p3.get() << std::endl;
	std::cout << "*p3       = " << *p3 << std::endl;
	
	int * p_empty;
	std::unique_ptr<int> p4(p_empty);
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "std::unique_ptr<int> p4(std::move(p_empty));" << std::endl;
	std::cout << " p4.get() = " <<  p4.get() << std::endl;
	//std::cout << "*p4       = " << *p4 << std::endl;
	p4.release();


	p4.reset(p3.get());
	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << " p4.reset(p3.get());" << std::endl;
	std::cout << " p4.get() = " <<  p4.get() << std::endl;
	std::cout << "*p4       = " << *p4 << std::endl;


	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << "f(p4); " << std::endl;
	f(std::move(p4));

	std::cout << "\n" << std::endl;
	std::cout << "---------------------------------- " << std::endl;
	std::cout << " p4.get() = " <<  p4.get() << std::endl;
	std::cout << "*p4       = " << *p4 << std::endl;

	}
	return 0;
}
