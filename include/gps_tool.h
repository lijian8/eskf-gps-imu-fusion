//
// Created by meng on 2021/2/19.
//

#ifndef GPS_IMU_FUSION_GPS_TOOL_H
#define GPS_IMU_FUSION_GPS_TOOL_H

#include "gps_data.h"
#include "Geocentric/LocalCartesian.hpp"

#include <deque>
#include <vector>

class GPSTool {
public:
    GPSTool() = default;

    GPSTool(double lon, double lat);

    static void LLAToLocalNED(GPSData &gps_data);

    static Eigen::Vector3d LLAToLocalNED(const Eigen::Vector3d &lla);

    static void ReadGPSData(const std::string &path, std::vector<GPSData> &gps_data_vec, int skip_rows = 1);

    static void ReadGPSData(const std::string &path, std::deque<GPSData> &gps_data_vec, int skip_rows = 1);

private:
    static GeographicLib::LocalCartesian geo_converter_; // only support ENU
};

#endif //GPS_IMU_FUSION_GPS_TOOL_H
