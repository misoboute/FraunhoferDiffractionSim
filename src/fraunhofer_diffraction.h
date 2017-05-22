#ifndef FRAUNHOFER_DIFFRACTION_H
#define FRAUNHOFER_DIFFRACTION_H

#include <functional>

class fraunhofer_diffraction {
public:
    fraunhofer_diffraction(
            int number_of_slits, double max_irradiance, double slit_width, double slit_separation, double wave_number);

    std::function<double(double)> get_irradiance_func();
    std::function<double(double)> get_wave_func();
    double irradiance_func(double theta);
    double wave_func(double theta);

    void set_max_irradiance(double irradiance);
    void set_number_of_slits(int slits);
    void set_slit_width(double width);
    void set_slit_separation(double separation);
    void set_wave_number(double wave_num);

private:
    double phase_difference(double distance, double theta);

    double m_wave_func_max;
    int m_number_of_slits;
    double m_slit_separation;
    double m_slit_width;
    double m_wave_number;
};

#endif /* FRAUNHOFER_DIFFRACTION_H */

