//#include "FraunhoferDiffraction.h"

#include <TApplication.h>
#include <TF1.h>

#include "fraunhofer_diffraction.h"

using namespace std;

void simulate_fraunhofer_diffraction() {

    // define function and set options
//     auto irradiance_func = [&] (double* theta, double* params) 
//     { 
//         fraunhofer.set_slit_separation(slit_width / params[0]);
//         fraunhofer.set_number_of_slits(params[1]);
//         return fraunhofer.irradiance_func(*theta); 
//     };
//   TF1 *Fnslit = new TF1("Fnslit", irradiance_func, -5.001, 5., 2);
//    Fnslit->SetNpx(500);
//    
//
//    // set parameters, as read in above
//    Fnslit->SetParameter(0, slit_width / slit_separation);
//    Fnslit->SetParameter(1, number_of_slits);
//
//    // draw the interference pattern for a grid with n slits
//    Fnslit->Draw();
}

int main(int argc, char ** argv) {
    TApplication app("Fraunhofer Diffraction", &argc, argv);
    double slit_separation, slit_width, wave_number, max_irradiance, plot_start, plot_end;
    int number_of_slits;
    
    cout << "Enter the number of slits (N): ";
    cin >> number_of_slits;
    cout << "Enter the slit width (b): ";
    cin >> slit_width;
    cout << "Enter the distance between adjacent slits (a): ";
    cin >> slit_separation;
    cout << "Enter the wave number (k): ";
    cin >> wave_number;
    cout << "Enter the maximum irradiance (I_0): ";
    cin >> max_irradiance;
    cout << "Enter plotting range start point (theta_1): ";
    cin >> plot_start;
    cout << "Enter plotting range end point (theta_2): ";
    cin >> plot_end;

    fraunhofer_diffraction fraunhofer(number_of_slits, max_irradiance, slit_width, slit_separation, wave_number);
    auto irradiance_func = [&fraunhofer] (double* theta, double* params) { return fraunhofer.irradiance_func(*theta); };
    TF1 irradiance_func_plot("Irradiance Function", irradiance_func, plot_start, plot_end, 0, 1);
    irradiance_func_plot.SetNpx(500);
    irradiance_func_plot.Draw();
//    auto wave_func = [&fraunhofer] (double* theta, double* params) { return fraunhofer.wave_func(*theta); };
//    TF1 wave_func_plot("Wave Function", wave_func, plot_start, plot_end, 0, 1);
//    wave_func_plot.SetNpx(5000);
//    wave_func_plot.Draw();
    app.Run();
    return 0;
}