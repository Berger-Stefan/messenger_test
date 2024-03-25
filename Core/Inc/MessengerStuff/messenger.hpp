/*
 * messager.hpp
 *
 *  Created on: Mar 24, 2024
 *      Author: stefan
 */

#ifndef INC_MESSENGERSTUFF_MESSENGER_HPP_
#define INC_MESSENGERSTUFF_MESSENGER_HPP_

#include <cstdint> // For fixed-width integer types


class Messenger {
private:
    uint64_t data; // Use a 64-bit integer

public:
    // Constructor (optional for initialization)
    Messenger(uint16_t targetTaskId = 0, uint16_t payloadId = 0, uint32_t payload = 0) {
        set_target_task_id(targetTaskId);
        set_payload_id(payloadId);
        set_payload(payload);
    }

    Messenger();

    void set_target_task_id(uint16_t targetTaskId) {
        data = (data & ~0xFFFF000000000000ULL) | (uint64_t(targetTaskId) << 48);
    }

    void set_payload_id(uint16_t payloadId) {
        data = (data & ~0x0000FFFF00000000ULL) | (uint64_t(payloadId) << 32);
    }

    void set_payload(uint32_t payload) {
        data = (data & ~0x00000000FFFFFFFFULL) | payload;
    }

    uint16_t get_target_task_id() const {
        return (data >> 48) & 0xFFFF;
    }

    uint16_t get_payload_id() const {
        return (data >> 32) & 0xFFFF;
    }

    uint32_t get_payload() const {
        return data & 0xFFFFFFFF;
    }
};

#endif /* INC_MESSENGERSTUFF_MESSENGER_HPP_ */
