#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//ô-èÿ ââîäà ıëåìåíòîâ
vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

//ô-èÿ ğàñ÷åòà ìèíèìóììà è ìàêñèìóìó
void
find_minmax(const vector<double>& numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }
}
//ĞÀÑ×ÅÒ ÊÎËÈÅÑÒÂÀ ×ÈÑÅË  Â ÑÒÎËÁÀÖÀÕ Ô-Èß
void
make_histogram(const vector<double>& numbers /*,double bin_size, /*size_t number_count,
               size_t bin_count*/, double min, double max, vector<double>& bins)
{   double bin_count = size(bins);
    double number_count= size(numbers);
     double bin_size = (max-min)/bin_count;
    for (size_t i = 0; i < number_count; i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }

}

// ÎÒÎÁĞÀÆÅÍÈÅ ÃÈÑÒĞÎÃĞÀÌÌÛ Ô-Èß
void
show_histogram(vector<double>& bins)
{   const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 ;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    const double scaling_factor = (double)MAX_ASTERISK / max_count;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            height = (size_t)(bin * scaling_factor);
        }
        //cout<< height<<"  "<<scaling_factor;


        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }

}

int
main()
{

    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);


    size_t bin_count;


    cerr << "Enter column count: ";
    cin >> bin_count;
    vector<double> bins
    ;
    if (bin_count == 0)
    {
        bin_count = sqrt(number_count);
        bins.resize(bin_count);
        if (bin_count > 25)
        {
            bin_count = 1 + log2(number_count);
            bins.resize(bin_count);
            cout<< bin_count<<"po formule sterdjesa"<<'\n';
        }
        else
        {
            cout<<bin_count<<"po formule sqrt(N)"<<'\n';
        }

    }
    else
    {
        bins.resize(bin_count);
    }


    double min = numbers[0];
    double max = numbers[0];
    find_minmax(numbers,min,max);

    //double bin_size = (max-min)/bin_count;
    make_histogram(numbers /*bin_size,  number_count, bin_count*/,  min,  max, bins);
    /*for (size_t i = 0; i < number_count; i++)
    {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }*/


    show_histogram(bins);
    /*const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1 ;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    const double scaling_factor = (double)MAX_ASTERISK / max_count;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            height = (size_t)(bin * scaling_factor);
        }
        //cout<< height<<"  "<<scaling_factor;


        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    */
    return 0;
}
