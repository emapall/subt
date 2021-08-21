#include "sample_system.hh"
#include <stdio.h>

using namespace ignition;
using namespace gazebo;
using namespace sample_system;


SampleSystem::SampleSystem() {
}

SampleSystem::~SampleSystem() {
}

void SampleSystem::PreUpdate(const UpdateInfo &_info, EntityComponentManager &_ecm) {
  EntityComponentManager &_ecm_non_const = const_cast<EntityComponentManager&>(_ecm);
  
  if(_info.paused)
    return;
  //ignmsg<<this->base_link.Name(_ecm).value()<<std::endl;
  if(this->base_link.WorldPose(_ecm).has_value()){
    math::Pose3d lv = this->base_link.WorldPose(_ecm).value();
    //math::Vector3d la = this->base_link.WorldAngularVelocity(_ecm).value();

    ignmsg<<lv<<"\n";
  }
  else{
    //ignmsg<<"Vector does not have Pose"<<base_link.Valid(_ecm)<<"\n";
    //Entity link_ent = this->base_link.Entity();
    //auto pos = _ecm.Component<components::WorldPose>(link_ent);
    //ignmsg<<pos;
    std::cout<<".";
  }
  //ignmsg<<"Adding this wrench\n";
  this->base_link.AddWorldWrench(_ecm_non_const,math::Vector3d(1,2,0),math::Vector3d(3,3,3));
  
}

void SampleSystem::PostUpdate(const UpdateInfo &_info, const EntityComponentManager &_ecm) {


}

void SampleSystem::Configure(const Entity &_entity,
                         const std::shared_ptr<const sdf::Element> &_sdf,
                         EntityComponentManager &_ecm,
                         EventManager &/*_eventMgr*/) {
  ignition::gazebo::Model model = Model(_entity);
  ignmsg<<"!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!\n"
            <<"!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!"
            <<"\n!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!\n!!!!!!!!!!!!!!!!!"
            <<"\n!!!!!!!!!!!!!!!!!\n"<<model.Name(_ecm);
  this->base_link = ignition::gazebo::Link(model.LinkByName(_ecm,"base_link"));
  ignmsg<<base_link.Name(_ecm).value();
}

