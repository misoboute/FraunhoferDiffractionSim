#include "Challenge.h"

#include <iomanip>

#include "../../Enhanced-Elastography/EnhancedElastography/PDebug.h"

const int NumLetters = 26;

int Challenge::main(std::istream& cin, std::ostream& cout) {
    int n;
    cin >> n;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        int num = 0;
        cin >> num;
        if (num > 0)
            pos++;
        else if (num < 0)
            neg++;
    }
    double posFrac = static_cast<double> (pos) / n,
            negFrac = static_cast<double> (neg) / n,
            zeroFrac = 1 - negFrac - posFrac;
    cout << std::setprecision(6) << std::fixed << posFrac << std::endl;
    cout << std::setprecision(6) << std::fixed << negFrac << std::endl;
    cout << std::setprecision(6) << std::fixed << zeroFrac << std::endl;
    return 0;
}
