#pragma once

#include "Message.h"
#include <Buffer.hpp>
#include <Structs/Objects.h>

struct ServerScriptUpdate final : ServerMessage
{
    ServerScriptUpdate()
        : ServerMessage(kServerScriptUpdate)
    {
    }

    void SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept override;
    void DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept override;

    bool operator==(const ServerScriptUpdate& achRhs) const noexcept
    {
        return Data == achRhs.Data &&
            GetOpcode() == achRhs.GetOpcode();
    }

    Objects Data{};
};
