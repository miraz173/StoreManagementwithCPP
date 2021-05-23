#include <iostream>
#include <fstream>
#include <cstring>

//using std::string, std::cout, std::cin, std::ofstream, std::getline;
using namespace std;

class product
{
private:
	float Wholesale_Price = 0;
	float Retail_Price = 0;
	std::string Supplier = "N/A";
	std::string Note = "N/A";
public:
	std::string Name="N/A";
	int Stock_Amount=0;

	void UpdateRetailPrice(float New_Retail_Price)
	{
		Retail_Price = New_Retail_Price;
	}
	void UpdateProductAmount(int New_Stock_Amount)
	{
		Stock_Amount = New_Stock_Amount;
	}
	void UpdateWholesale_price(float New_Wholesale_Price)
	{
		Wholesale_Price = New_Wholesale_Price;
	}
	void NewProduct(std::string New_Name, int New_Stock_Amount, float New_Wholesale_Price, float New_Retail_Price, std::string New_Supplier, std::string New_Note)
	{
		Name = New_Name;
		Retail_Price = New_Retail_Price;
		Wholesale_Price = New_Wholesale_Price;
		Stock_Amount = New_Stock_Amount;
		Supplier = New_Supplier;
		Note = New_Note;
	}
	void Admin_Print_Product_Details()
	{
		cout <<"---Product Description---\n"<<"Product Name: "<< Name <<'\n' <<"Wholesale Price (TK): "<<Wholesale_Price<<'\n'<<"Retail Price (TK): " <<Retail_Price <<'\n'<<"Stock Amount (KG): "<< Stock_Amount <<'\n' <<"Supplier Name: " <<Supplier<<'\n' <<"Note: "<< Note <<std::endl;
	}
};

string StringInput();
void ReadProductFromFile(product Products);


int main(int argc, char const *argv[])
{
	product Products[10];
	//Products[1].NewProduct( "Apple", 150, 230, 240, "Bengal Greens", "N/A" );
	//std::cout << Products[1].Stock_Amount;
	Products[5].Admin_Print_Product_Details();
	return 0;
}

string StringInput()  //returns null-terminated string
{
    string input;
    getline(cin, input);
    while(input.length()==0)
    {
        getline(cin, input);
    }
    return input.c_str();
}

void ReadProductFromFile(product Products)
{
	string Name, Supplier, Note, Wholesale_Price, Retail_Price, Stock_Amount;

	ifstream ReadProductFromFile;
	ReadProductFromFile.open("product.txt");

	if (!ReadProductFromFile)
	{
		perror("Priduct File failed to open");
	}

	while(!EOF)
        {
        getline(ReadProductFromFile, Name); getline(ReadProductFromFile, Wholesale_Price); getline(ReadProductFromFile, Retail_Price); getline(ReadProductFromFile, Stock_Amount); getline(ReadProductFromFile, Supplier); getline(ReadProductFromFile, Note);
        Products.Name = Name, Products.Stock_Amount = Stock_Amount; Products.UpdateWholesale_price(Wholesale_Price); Products.UpdateProductAmount(Stock_Amount); Products.UpdateRetailPrice(Retail_Price);
        return Products;
        }
}
