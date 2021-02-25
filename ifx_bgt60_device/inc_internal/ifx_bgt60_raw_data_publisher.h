/**
* \copyright
* MIT License
*
* Copyright (c) 2020 Infineon Technologies AG
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE
*
* \endcopyright
*
* \author Infineon Technologies AG
*
* \file ifx_bgt60_raw_data_publisher.h
*
* \brief   Publish raw data in the form of customized message type
*         'ifx_bgt60_device/ifx_bgt60_raw_data'
*
*
* @{
*/

#ifndef IFX_BGT60_RAW_DATA_PUBLISHER_H_
#define IFX_BGT60_RAW_DATA_PUBLISHER_H_


#include <ros/ros.h>
#include <thread>
#include <memory>

/* Generated message header file */
#include <ifx_bgt60_device/ifx_bgt60_raw_data.h>

#include "ifx_ring_buffer.h"


namespace ifx
{

class Bgt60RawDataPublisher
{
public:
    /**
     * @brief Construct a new Radar Publisher object
     */
    Bgt60RawDataPublisher() = default;
    /**
     * @brief Destroy the Radar Publisher object
     */
    ~Bgt60RawDataPublisher();
    /**
     * @brief Initialize Bgt60RawDataPublisher object
     *
     * @param node              Associated ROS node
     * @param pub_topic_name    Publish topic name
     * @param pub_queue_size    Publish queue size
     * @param buff              Buffer of data to be published
     * @return true             Initialization succeed
     * @return false            Initialization fail
     */
    bool init(ros::NodeHandle& node,
              const std::string& pub_topic_name,
              const int pub_queue_size,
              std::shared_ptr<RingBuffer<std::unique_ptr<
                ifx_bgt60_device::ifx_bgt60_raw_data> > > buff);
    /**
     * @brief Get initialization status
     */
    inline bool isRunning() { return _running; }

private:
    /**
     * @brief Get raw data from ring buffer, and publish
     *        customized message in a separate thread
     */
    void publishData();

    bool            _running = { false };
    ros::Publisher  _publisher;
    std::thread     _pub_thread;

    std::shared_ptr<RingBuffer<std::unique_ptr<ifx_bgt60_device::ifx_bgt60_raw_data> > > _buff = { nullptr };
};

} // namespace ifx
#endif // IFX_BGT60_RAW_DATA_PUBLISHER

/**
* @}
*/