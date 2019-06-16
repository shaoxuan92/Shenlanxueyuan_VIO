#ifndef HEADER_POSEUPDATE_H
#define HEADER_POSEUPDATE_H

#include "Converter.h"
class PoseUpdate
{
public:	
	template <typename T>
	T UpdatePose(T pose, T updatepose)
	{
		return pose * updatepose;
	};
	
// 	Sophus::SO3 UpdatePose(Sophus::SO pose, Sophus::SO updatepose)
// 	{
// 		return pose * updatepose;
// 	};
// 
// 	Eigen::Quaterniond UpdatePose(Eigen::Quaterniond pose, Eigen::Quaterniond updatepose)
// 	{
// 		return pose * updatepose;
// 	};
	Eigen::Vector3d SetUpateso3(Eigen::Vector3d vupdateso3)
	{
		vUpdateso3 = vupdateso3;
		return vUpdateso3;
	};
	Eigen::Vector3d GetUpateso3()
	{
		return vUpdateso3;
	};
private:
	Eigen::Vector3d vUpdateso3 = Eigen::Vector3d(0.0,0,0);
};

#endif
