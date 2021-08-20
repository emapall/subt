#include <ignition/gazebo/System.hh>
#include <stdio.h>
namespace sample_system
{
  class SampleSystem:
    // This class is a system.
    public ignition::gazebo::System,
    // This class also implements the ISystemPostUpdate interface.
    public ignition::gazebo::ISystemPostUpdate
  {
    public: SampleSystem();
    public: ~SampleSystem() override;
    public: void PostUpdate(const ignition::gazebo::UpdateInfo &_info,
                const ignition::gazebo::EntityComponentManager &_ecm) override;
  };
}

#include <ignition/plugin/Register.hh>
// Include a line in your source file for each interface implemented.
IGNITION_ADD_PLUGIN(
    sample_system::SampleSystem,
    ignition::gazebo::System,
    sample_system::SampleSystem::ISystemPostUpdate)