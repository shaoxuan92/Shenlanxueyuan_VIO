#ifndef HEADER_CONVERTER_H
#define HEADER_CONVERTER_H

#include<Eigen/Core>
#include<Eigen/Geometry>
#include"/home/lin/Desktop/js_308/Sophus/sophus/so3.h"
#include"/home/lin/Desktop/js_308/Sophus/sophus/se3.h"


class Converter 
{
public:
	static Sophus::SO3 RotationMatrix2SO3(const Eigen::Matrix3d& mPoseInput)
	{
		return Sophus::SO3(mPoseInput);
	};
	
	static Eigen::Quaterniond RotationMatrix2Quaternion(const Eigen::Matrix3d& mPoseInput)
	{
		return Eigen::Quaterniond(mPoseInput);
	};
	
	
	static Sophus::SO3 so32SO3(const Eigen::Vector3d& mPoseInput)
	{
		return Sophus::SO3::exp(mPoseInput);
	};
	
	static Eigen::Quaterniond so3Quaternion(const Eigen::Vector3d& mPoseInput)
	{
		return Eigen::Quaterniond(so32SO3(mPoseInput).matrix());
	};
};
#endif