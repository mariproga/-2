#include <iostream>
#include <vector>
#include <algorithm>

class VectorArray
{
public:
    std::vector<double> elements;

    VectorArray(int size)
    {
        elements.resize(size);
    }

    void inputElements()
    {
        for (auto& element : elements)
            std::cin >> element;
    }

    void displayOperations(const VectorArray& other)
    {
        std::cout << "summa=";
        for (int i = 0; i < elements.size(); i++)
            std::cout << " " << elements[i] + other.elements[i];
        std::cout << std::endl;

        std::cout << "raznost=";
        for (int i = 0; i < elements.size(); i++)
            std::cout << " " << elements[i] - other.elements[i];
        std::cout << std::endl;

        std::cout << "proizv=";
        for (int i = 0; i < elements.size(); i++)
            std::cout << " " << elements[i] * other.elements[i];
        std::cout << std::endl;

        std::cout << "delenie=";
        for (int i = 0; i < elements.size(); i++)
            std::cout << " " << elements[i] / other.elements[i];
        std::cout << std::endl;
    }

    void multiplyByNumber(VectorArray& other)
    {
        double number;
        std::cin >> number;

        for (auto& element : elements)
            element *= number;

        for (auto& element : other.elements)
            element *= number;

        std::cout << std::endl << "mult chislo massiv1=";
        for (const auto& element : elements)
            std::cout << " " << element;

        std::cout << std::endl << "mult chislo massiv2=";
        for (const auto& element : other.elements)
            std::cout << " " << element;
    }


    void checkEquality(const VectorArray& other)
    {
        if (elements == other.elements)
            std::cout << std::endl << "massivy ravny";
        else
            std::cout << std::endl << "massivy ne ravny";
    }
};

int main()
{
    int vectorSize;
    std::cin >> vectorSize;

    VectorArray firstVector(vectorSize);
    VectorArray secondVector(vectorSize);

    firstVector.inputElements();
    secondVector.inputElements();

    std::cout << "massiv1= ";
    for (const auto& element : firstVector.elements)
        std::cout << element << " ";
    std::cout << std::endl;

    std::cout << "massiv2= ";
    for (const auto& element : secondVector.elements)
        std::cout << element << " ";
    std::cout << std::endl;

    firstVector.displayOperations(secondVector);

    firstVector.multiplyByNumber(secondVector);
    //secondVector.multiplyByNumber(firstVector);

    firstVector.checkEquality(secondVector);

    return 0;
}