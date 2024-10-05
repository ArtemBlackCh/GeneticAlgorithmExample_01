#include <iostream>
#include <math.h>
#include <random>
#include <Vector>
#include <List>
#include <conio.h>

using namespace std;

double Funktion(double x, double y)
{
    //double z = pow(sin(x), 3) + pow(cos(y), 1 / 3);

    //double z = -pow(x, 2) - pow(y, 2) + 5;

    double z = sin(x) * cos(y);

    return z;
}

bool probability(int persent)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);

    return persent >= dist(rng);
}

int IntRandom(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

    return dist(rng);
}

double DoubleRandom(double min, double max)
{
    int t = 3; 
    int n = pow(10,t) * abs (min - max);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, n);

    int a = dist(rng); 

    double b = (a * 1.0) / n; 

    b *= (max - min); 

    b += min; 

    return b;
}


class Object {
public : 
    
    double _x;
    double _y;
    double _z;

    void NewObject()
    {
        _x = DoubleRandom(-10, 10);
        _y = DoubleRandom(-10, 10);
        _z = Funktion(_x,_y);
    }

    void SetObject(double x, double y)
    {
        _x = x;
        _y = y;
        _z = Funktion(x, y); 
    }
};

vector<Object> Sort(vector<Object> Vector)
{
    Object buffer;

    for (int j = 0 ; j < Vector.size() - 2 ; j++)
    { 
        for (int i = 0; i < Vector.size() - 1; i++)
        {
            if (Vector[i]._z < Vector[i + 1]._z)
            {
                buffer = Vector[i];
                Vector[i] = Vector[i + 1];
                Vector[i + 1] = buffer;
            }
        }
    }

    return Vector;
}

double Mutate(double num)
{
    double new_num = num + num * DoubleRandom(-0.5, 0.5);
    return new_num;
}

vector<Object> Mix(vector<Object> Vector)
{
    vector<Object> new_vector;

    vector<vector<short>> cross_ratio = { {0,0},{0,1},{1,0},{0,2},{2,0},{1,3},{3,1},{2,4},{4,2} };

    Object new_object;

    int x_num,y_num;
    double x,y;

    for (int i = 0; i < cross_ratio.size(); i++)
    {
        x_num = cross_ratio[i][0];
        y_num = cross_ratio[i][1];

        x = Vector[x_num]._x;
        y = Vector[y_num]._y;

        if (i != 0)
        {
            if (probability(40))
                x = Mutate(x);

            if (probability(40))
                y = Mutate(y);
        }

        new_object.SetObject(x, y);
        new_vector.push_back(new_object);
    }

    for (int i = 0; i < Vector.size() - cross_ratio.size(); i++)
    {
        new_object.NewObject();
        new_vector.push_back(new_object);
    }

    return new_vector;
}

int main()
{
    Object new_object;
    vector<Object> population;

    for (int i = 0; i < 10; i++)
    {
        new_object.NewObject(); 
        population.push_back(new_object);
        //cout << new_object._x << " " << new_object._y << " " << new_object._z << "\n";
    }

    population = Sort(population);

    cout << "--- popoulation 0 ---" << "\n";
    for (int i = 0; i < 10; i++)
    {
        cout << population[i]._x << " " << population[i]._y << " " << population[i]._z << "\n";
    }
    cout << "\n";

    int num_of_generations;
    int step;

    cout << "input number of generations :";
    cin >> num_of_generations;
    cout << "\n";
    cout << "input step :";
    cin >> step;
    cout << "\n";

    for (int t = 0; t < num_of_generations; t++)
    {

        population = Mix(population);

        population = Sort(population);

        if(t % step == step - 1 )
        { 
            system("cls");
            cout << (t + 1) * 100 / num_of_generations << "%\n";
            cout << "--- popoulation " << t + 1 << " --- " <<"\n";
            for (int p = 0; p < 10; p++)
            {
                cout << population[p]._x << " " << population[p]._y << " " << population[p]._z << "\n";
            }
            cout << "\n";
        }
    }

    cout << "x = " << population[0]._x << "\n";
    cout << "y = " << population[0]._y << "\n";
    cout << "z = " << population[0]._z << "\n";
}
