#include "mTLowerAndUpperBound.h"
#include "mTTrue.h"
#include <array>
#include <iostream>

static int counter = 1;

double get_mt_bound(const std::array<double, 4>& v1,
                    const std::array<double, 4>& v2,
                    const std::array<double, 2>& ptmiss) {
    // Mass of the tau lepton.
    const double m_tau = 1.77682;
    return Lester::mTLowerAndUpperBound(v1[0], v1[1], v1[2], v1[3],
                                        v2[0], v2[1], v2[2], v2[3],
                                        ptmiss[0], ptmiss[1], m_tau, true);
}

double get_mt_true(const std::array<double, 4>& v1,
                   const std::array<double, 4>& v2,
                   const std::array<double, 2>& ptmiss) {
    return Lester::mTTrue(v1[0], v1[1], v1[2], v1[3],
                          v2[0], v2[1], v2[2], v2[3],
                          ptmiss[0], ptmiss[1], 0.0);
}

void print_result(const double& mt_bound, const double& mt_true) {
    std::cout << "(" << counter
              << ") mTBound = " << mt_bound << ", "
              << "mTTrue = " << mt_true << '\n';
    ++counter;
}

int main() {
    // The four-momentum of the visible systems: {E, Px, Py, Pz}.
    std::array<double, 4>
        v1{{70.991623018, 24.4994998687, -36.586361435, 55.682416967}};
    std::array<double, 4>
        v2{{28.6165908531, -5.01150522757, 6.56305506273, 27.3938843585}};
    // The transverse momentum of the invisible system: {Px, Py}.
    std::array<double, 2> ptmiss{{-22.378734312890003, 30.114831829400003}};
    // (1) mTBound = 97.0731, mTTrue = 92.4299
    print_result(get_mt_bound(v1, v2, ptmiss), get_mt_true(v1, v2, ptmiss));

    v1 = {{48.9748211593, -4.25420053069, -18.0298062078, -45.3358742472}};
    v2 = {{31.8867647632, 5.99984472641, 29.4269106812, -10.7147131691}};
    ptmiss = {{-1.4755369473799993, -10.912496205699995}};
    // (2) mTBound = 71.584, mTTrue = 69.2927
    print_result(get_mt_bound(v1, v2, ptmiss), get_mt_true(v1, v2, ptmiss));

    v1 = {{23.4528608023, 22.4219337654, -6.78381619743, -1.12349445812}};
    v2 = {{23.11902353941, -12.217856512680001, 4.31480614675, -19.12852757138}};
    ptmiss = {{-10.62280146074, 3.894942135880001}};
    // (3) mTBound = 54.8676, mTTrue = 53.2316
    print_result(get_mt_bound(v1, v2, ptmiss), get_mt_true(v1, v2, ptmiss));

    v1 = {{44.6734172231, -7.60863717246, 22.06059903779, -38.08630179223}};
    v2 = {{58.3709791011, 4.916778144609999, -15.65711629521, 56.0084303585}};
    ptmiss = {{2.418267922405, -6.786272931236}};
    // (4) mTBound = 119.458, mTTrue = 108.677
    print_result(get_mt_bound(v1, v2, ptmiss), get_mt_true(v1, v2, ptmiss));

    v1 = {{48.5409522686, 15.026008527450001, -46.1157046709, -1.7967212585999999}};
    v2 = {{57.980358045900005, -17.81567839581, 54.942445595799995, -4.92558441941}};
    ptmiss = {{2.0606581585700003, -7.0937926384}};
    // (5) mTBound = 113.69, mTTrue = 113.68
    print_result(get_mt_bound(v1, v2, ptmiss), get_mt_true(v1, v2, ptmiss));
}
