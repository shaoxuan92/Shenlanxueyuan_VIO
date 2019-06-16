#include "PoseUpdate.h"
#include "Converter.h"
#include<iostream>
using namespace std;
// template <typename T>
// T UpdatSePose(T pose, T updatepose){};
int main(int argc, char* [])
{
	//Initial Pose
	Eigen::Matrix3d mEigenPose = Eigen::Matrix3d::Random();	

	PoseUpdate oPoseUpdate;
	
	//Update by Sophus::SO3
	Sophus::SO3 SO3Pose = Converter::RotationMatrix2SO3(mEigenPose);
	oPoseUpdate.SetUpateso3(Eigen::Vector3d(0.01,0.02,0.03));
	Sophus::SO3 SO3PoseUpdate = Converter::so32SO3(oPoseUpdate.GetUpateso3());
	Sophus::SO3 SO3PoseUpdated = oPoseUpdate.UpdatePose(SO3Pose,SO3PoseUpdate);
	//Update by quanternion
	Eigen::Quaterniond QuanternionPose = Converter::RotationMatrix2Quaternion(mEigenPose);
	//Eigen::Quaterniond QuanternionPoseUpdate = Converter::so3Quaternion(oPoseUpdate.GetUpateso3());
	Eigen::Quaterniond NewQuaterniondPoseUpdate = Eigen::Quaterniond(1,0.005,0.01,0.015);
	Eigen::Quaterniond QuanternionPoseUpdated = oPoseUpdate.UpdatePose(QuanternionPose,NewQuaterniondPoseUpdate);
	
	//Results:
	cout << "Update by SO3: " << endl << SO3PoseUpdated.matrix()<<endl;
	cout << "Update by quanternion: " << endl<< Sophus::SO3(QuanternionPoseUpdated).matrix()<<endl;
	
}