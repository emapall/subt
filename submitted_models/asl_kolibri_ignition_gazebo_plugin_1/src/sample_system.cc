#include "sample_system.hh"

using namespace sample_system;
SampleSystem::SampleSystem()
{
}
SampleSystem::~SampleSystem()
{
}
void SampleSystem::PostUpdate(const ignition::gazebo::UpdateInfo &_info,
    const ignition::gazebo::EntityComponentManager &_ecm)
{
  ignmsg << "SampleSystem::PostUpdate" << std::endl;
  std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";

}