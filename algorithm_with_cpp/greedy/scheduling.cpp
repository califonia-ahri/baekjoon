#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T>
vector<T> compute_waiting_times(vector<T>& service_times)
// sum all wating time for average
{
    vector<T> W(service_times.size());
    W[0] = 0;

    for(auto i=1;i<service_times.size();i++)
        W[i] = W[i-1] + service_times[i-1];

    return W;
}

template<typename T>
void print_vector(vector<T>& V)
{
    for(auto &i:V)
    {
        cout.width(2);
        cout<<i<<" ";
    }
    cout<<endl;
}

template<typename T>
void compute_and_print_waiting_times(vector<T> &service_times)
{
    auto waiting_times = compute_waiting_times<int>(service_times);

    cout<<"- computing time: ";
    print_vector<T>(service_times);

    cout<<"- wating time: ";
    print_vector<T>(waiting_times);

    auto ave_wating_times = accumulate(waiting_times.begin(), waiting_times.end(), 0.0)/waiting_times.size();
    cout<<"- average waiting time: "<<ave_wating_times;

    cout<<endl;
}

int main(int argc, char* argv[])
{
    vector<int> service_times = { 8,1,2,4,9,2,3,5};

    cout<<"[first service time & wating time]"<<endl;
    compute_and_print_waiting_times<int>(service_times);

    // sort service time
    cout<<endl;
    cout<<"[first service time & waiting time]"<<endl;
    compute_and_print_waiting_times<int>(service_times);
}