#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct order {
    string name;
    int quantity;
    double price_per_unit;
};

int main() {
	setlocale(LC_ALL, "rus");
	int count;
	cout << "Введите количесво товаров:";
	cin >> count;

	double summa, ob;
	order* res = new order[count];
	for(int i=0; i < count; i++){
		string nam;
		cout << "Введите наименование товара " << i+1 << ":";
		cin >> nam;
		res[i].name = nam;

		cout << "Введите количество единиц товара " << i+1 << ":";
		cin >> res[i].quantity;

		cout << "Введите цену за единицу товара " << i+1 << ":";
		cin >> res[i].price_per_unit;

		summa = res[i].price_per_unit * res[i].quantity;
		cout << "Общая стоимость заказа: " << summa << endl;
		ob += summa;
	}

	sort(res, res + count, [](const order& a, const order& b) {
		return a.name < b.name;
	});

	for(int i=0; i < count; i++){
		cout << i+1 << " товар:" << res[i].name << " - количество: " << res[i].quantity << ", цена за единицу товара: " << res[i].price_per_unit << endl;
	}

	cout << "Общая сумма: " << ob;
	return 0;
}
