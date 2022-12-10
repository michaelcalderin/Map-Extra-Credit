#include <iostream>
#include <random>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{
    
    //set up random number generator
    const int min = 0;
    const int max = INT_MAX;
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> distr(min, max);
    int rand_num;

    //insert 10k random keys into map
    map<int, int> map10k;

    for (int i = 0; i < 10000; ++i) {

        rand_num = distr(generator);

        while (map10k.find(rand_num) != map10k.end()) {

            rand_num = distr(generator);

        }

        map10k[rand_num] = 0;

    }

    //insert 10k random keys into unordered_map
    unordered_map<int, int> unordered_map10k;
    
    for (int i = 0; i < 10000; ++i) {

        rand_num = distr(generator);

        while (unordered_map10k.find(rand_num) != unordered_map10k.end()) {

            rand_num = distr(generator);

        }

        unordered_map10k[rand_num] = 0;

    }

    //insert 100k random keys into map
    map<int, int> map100k;

    for (int i = 0; i < 100000; ++i) {

        rand_num = distr(generator);

        while (map100k.find(rand_num) != map100k.end()) {

            rand_num = distr(generator);

        }

        map100k[rand_num] = 0;

    }

    //insert 100k random keys into unordered_map
    unordered_map<int, int> unordered_map100k;

    for (int i = 0; i < 100000; ++i) {

        rand_num = distr(generator);

        while (unordered_map100k.find(rand_num) != unordered_map100k.end()) {

            rand_num = distr(generator);

        }

        unordered_map100k[rand_num] = 0;

    }

    //OPERATION 1: insert() for 10k elements
    auto start = high_resolution_clock::now();
    map10k.insert(make_pair(-1,0));
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << "insert() in 10k size map took " << duration.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unordered_map10k.insert(make_pair(-1,0));
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "insert() in 10k size unordered_map took " << duration.count() << " nanoseconds" << endl;

    //OPERATION 2: find() for 10k elements
    cout << endl;
    start = high_resolution_clock::now();
    map10k.find(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "find() in 10k size map took " << duration.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unordered_map10k.find(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "find() in 10k size unordered_map took " << duration.count() << " nanoseconds" << endl;

    //OPERATION 3: erase() for 10k elements
    cout << endl;
    start = high_resolution_clock::now();
    map10k.erase(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "erase() in 10k size map took " << duration.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unordered_map10k.erase(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "erase() in 10k size unordered_map took " << duration.count() << " nanoseconds" << endl;

    //OPERATION 1: insert() for 100k elements
    cout << endl;
    start = high_resolution_clock::now();
    map100k.insert(make_pair(-1, 0));
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "insert() in 100k size map took " << duration.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unordered_map100k.insert(make_pair(-1, 0));
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "insert() in 100k size unordered_map took " << duration.count() << " nanoseconds" << endl;

    //OPERATION 2: find() for 100k elements
    cout << endl;
    start = high_resolution_clock::now();
    map100k.find(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "find() in 100k size map took " << duration.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unordered_map100k.find(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "find() in 100k size unordered_map took " << duration.count() << " nanoseconds" << endl;

    //OPERATION 3: erase() for 100k elements
    cout << endl;
    start = high_resolution_clock::now();
    map100k.erase(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "erase() in 100k size map took " << duration.count() << " nanoseconds" << endl;

    start = high_resolution_clock::now();
    unordered_map100k.erase(-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(stop - start);
    cout << "erase() in 100k size unordered_map took " << duration.count() << " nanoseconds" << endl;
    
}