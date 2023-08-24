// Задача 2. Остальные операции с дробями.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	void Reduction() {
		int less, j;
		do {
			if (numerator_ < denominator_)
				less = numerator_;
			else
				less = denominator_;
			for (j = less; j > 0; j--) {
				if (!(numerator_ % j) && !(denominator_ % j)) {
					numerator_ /= j;
					denominator_ /= j;
					break;
				}
			}
		} while (j != 1);
	}

	int get_numerator_() { return numerator_; }
	int get_denominator_() { return denominator_; }
	Fraction operator + (const Fraction& other) { return Fraction((this->numerator_ * other.denominator_ + this->denominator_ * other.numerator_), (this->denominator_ * other.denominator_)); }
	Fraction operator - (const Fraction& other) { return Fraction((this->numerator_ * other.denominator_ - this->denominator_ * other.numerator_), (this->denominator_ * other.denominator_)); }
	Fraction operator * (const Fraction& other) { return Fraction((this->numerator_ * other.numerator_), (this->denominator_ * other.denominator_)); }
	Fraction operator / (const Fraction& other) { return Fraction((this->numerator_ * other.denominator_), (this->denominator_ * other.numerator_)); }

	Fraction& operator ++ () { numerator_ += denominator_, denominator_; return *this; }
	Fraction& operator -- () { numerator_ -= denominator_, denominator_; return *this; }

	Fraction operator ++ (int) { Fraction copy(*this); numerator_ += denominator_, denominator_; return copy; }
	Fraction operator -- (int) { Fraction copy(*this); numerator_ -= denominator_, denominator_; return copy; }

};




int main()
{
	setlocale(LC_ALL, "ru");

	int A1, B1, A2, B2;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> A1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> B1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> A2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> B2;

	Fraction f1(A1, B1);
	Fraction f2(A2, B2);
	Fraction f3(0, 0);
	
	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " + " << f2.get_numerator_() << "/" << f2.get_denominator_() << " = ";
	f3 = f1 + f2;
	std::cout << f3.get_numerator_() << "/" << f3.get_denominator_() << '\n';
	

	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " - " << f2.get_numerator_() << "/" << f2.get_denominator_() << " = ";
	f3 = f1 - f2;
	std::cout <<  f3.get_numerator_() << "/" << f3.get_denominator_() << '\n';
	

	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " * " << f2.get_numerator_() << "/" << f2.get_denominator_() << " = ";
	f3 = f1 * f2;
	f3.Reduction();
	std::cout << f3.get_numerator_() << "/" << f3.get_denominator_() << '\n';
	

	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << " / " << f2.get_numerator_() << "/" << f2.get_denominator_() << " = ";
	f3 = f1 / f2;
	f3.Reduction();
	std::cout << f3.get_numerator_() << "/" << f3.get_denominator_() << '\n';


	std::cout << "++" << f1.get_numerator_() << "/" << f1.get_denominator_() << " * " << f2.get_numerator_() << "/" << f2.get_denominator_() << " = ";
	f3 = ++f1 * f2;
	f3.Reduction();
	std::cout << f3.get_numerator_() << "/" << f3.get_denominator_() << '\n';
	std::cout << "Значение дроби 1 = " << f1.get_numerator_() << "/ " << f1.get_denominator_() << std::endl;


	std::cout << f1.get_numerator_() << "/" << f1.get_denominator_() << "--" << " * " << f2.get_numerator_() << "/" << f2.get_denominator_() << " = ";
	f3 = f1-- * f2;
	f3.Reduction();
	std::cout <<  f3.get_numerator_() << "/" << f3.get_denominator_() << '\n';
	std::cout << "Значение дроби 1 = " << f1.get_numerator_() << "/ " << f1.get_denominator_() << std::endl;


	return 0;
}