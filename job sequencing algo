#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    char id;       // Job Id
    int dead;      // Deadline of job
    int profit;    // Profit if job is over before or on deadline
} Job;

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

int main() {
    int n;
    cout << "how many jobs?";
    cin >> n;
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
    }

    sort(jobs, jobs + n, comparison);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << jobs[i].id << "  " << jobs[i].dead << "  " << jobs[i].profit << endl;
    }

    int maxDeadline = jobs[0].dead;
    for (int i = 1; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].dead);
    }

    cout << "Maximum Deadline: " << maxDeadline << endl;

    char sequence[maxDeadline];  

   
    for (int i = 0; i < maxDeadline; i++) {
        sequence[i] = '-';
    }

   
    int sum=0;
    for (int i = 0; i < n; i++) {
        for (int j = min(maxDeadline, jobs[i].dead) - 1; j >= 0; j--) {
            if (sequence[j] == '-') {
                sequence[j] = jobs[i].id;
                sum=sum+ jobs[i].profit ;
                break;
            }
        }
    }

   
    cout << "Job Sequence: ";
    for (int i = 0; i < maxDeadline; i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;
    cout<<"max profit is:"<<sum;

    return 0;
}
