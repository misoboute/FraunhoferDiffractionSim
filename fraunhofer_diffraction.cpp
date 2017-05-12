#include "fraunhofer_diffraction.h"

#include <cmath>

fraunhofer_diffraction::fraunhofer_diffraction(
        int number_of_slits, double max_irradiance, double slit_width, double slit_separation, double wave_number) {
    set_max_irradiance(max_irradiance);
    set_slit_width(slit_width);
    set_slit_separation(slit_separation);
    set_wave_number(wave_number);
}

std::function<double(double) > fraunhofer_diffraction::get_irradiance_func() {
    return [&] (double theta) {
        return irradiance_func(theta);
    };
}

std::function<double(double) > fraunhofer_diffraction::get_wave_func() {
    return [&] (double theta) {
        return wave_func(theta);
    };
}

double fraunhofer_diffraction::irradiance_func(double theta) {
    return std::pow(wave_func(theta), 2);
}

double fraunhofer_diffraction::wave_func(double theta) {
    auto alpha = phase_difference(m_slit_separation, theta);
    auto beta = phase_difference(m_slit_width, theta);
    return m_wave_func_max * std::sin(m_number_of_slits * alpha) / alpha * std::sin(beta) / beta;
}

double fraunhofer_diffraction::phase_difference(double distance, double theta) {
    return m_wave_number / 2 * distance * std::sin(theta);
}

void fraunhofer_diffraction::set_max_irradiance(double irradiance) {
    m_wave_func_max = std::sqrt(irradiance);
}

void fraunhofer_diffraction::set_number_of_slits(int slits) {
    m_number_of_slits = slits;
}

void fraunhofer_diffraction::set_slit_width(double width) {
    m_slit_width = width;
}

void fraunhofer_diffraction::set_slit_separation(double separation) {
    m_slit_separation = separation;
}

void fraunhofer_diffraction::set_wave_number(double wave_num) {
    m_wave_number = wave_num;
}
