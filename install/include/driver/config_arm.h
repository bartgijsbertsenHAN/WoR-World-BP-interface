// Generated by gencpp from file driver/config_arm.msg
// DO NOT EDIT!


#ifndef DRIVER_MESSAGE_CONFIG_ARM_H
#define DRIVER_MESSAGE_CONFIG_ARM_H

#include <ros/service_traits.h>


#include <driver/config_armRequest.h>
#include <driver/config_armResponse.h>


namespace driver
{

struct config_arm
{

typedef config_armRequest Request;
typedef config_armResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct config_arm
} // namespace driver


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::driver::config_arm > {
  static const char* value()
  {
    return "437dcc9253614fa63d9b9cff189a86cc";
  }

  static const char* value(const ::driver::config_arm&) { return value(); }
};

template<>
struct DataType< ::driver::config_arm > {
  static const char* value()
  {
    return "driver/config_arm";
  }

  static const char* value(const ::driver::config_arm&) { return value(); }
};


// service_traits::MD5Sum< ::driver::config_armRequest> should match 
// service_traits::MD5Sum< ::driver::config_arm > 
template<>
struct MD5Sum< ::driver::config_armRequest>
{
  static const char* value()
  {
    return MD5Sum< ::driver::config_arm >::value();
  }
  static const char* value(const ::driver::config_armRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::driver::config_armRequest> should match 
// service_traits::DataType< ::driver::config_arm > 
template<>
struct DataType< ::driver::config_armRequest>
{
  static const char* value()
  {
    return DataType< ::driver::config_arm >::value();
  }
  static const char* value(const ::driver::config_armRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::driver::config_armResponse> should match 
// service_traits::MD5Sum< ::driver::config_arm > 
template<>
struct MD5Sum< ::driver::config_armResponse>
{
  static const char* value()
  {
    return MD5Sum< ::driver::config_arm >::value();
  }
  static const char* value(const ::driver::config_armResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::driver::config_armResponse> should match 
// service_traits::DataType< ::driver::config_arm > 
template<>
struct DataType< ::driver::config_armResponse>
{
  static const char* value()
  {
    return DataType< ::driver::config_arm >::value();
  }
  static const char* value(const ::driver::config_armResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // DRIVER_MESSAGE_CONFIG_ARM_H
