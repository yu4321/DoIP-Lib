#ifndef MESSAGE_H
#define MESSAGE_H

#include <vector>
#include "./payload_type.h"

namespace DoipLib
{
    /// @brief DoIP generic message
    class Message
    {
    private:
        uint8_t mProtocolVersion;
        PayloadType mPayloadType;

    protected:
        /// @brief DoIP message header size
        const std::size_t cHeaderSize{8};

        Message() noexcept = default;

        /// @brief Constructor
        /// @param protocolVersion DoIP ISO protocol version
        /// @param payloadType DoIP message payload type
        Message(uint8_t protocolVersion, PayloadType payloadType) noexcept;

        /// @brief Get message payload
        /// @param[out] payload Payload byte array
        virtual void GetPayload(std::vector<uint8_t> &payload) = 0;

        /// @brief Try to set message payload
        /// @param[in] payload Payload byte array
        /// @returns True if the payload is set successfully, otherwise false
        virtual bool TrySetPayload(const std::vector<uint8_t> &payload) = 0;

    public:
        /// @brief Serialize DoIP message
        /// @param[out] serializedMessage Serialize message byte array
        void Serialize(std::vector<uint8_t> &serializedMessage);

        /// @brief Try to deserialize DoIP message
        /// @param[in] serializedMessage Serialize message byte array
        /// @returns True if the deserialization is successful, otherwise false
        bool TryDeserialize(const std::vector<uint8_t> &serializedMessage);

        virtual ~Message() noexcept = default;
    };
}

#endif