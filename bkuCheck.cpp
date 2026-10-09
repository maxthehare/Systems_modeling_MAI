enum class CommandStatus : uint8_t
{
    NO_COMMAND = 0,   // Команда отсутствует
    VALID       = 1,  // Команда получена и подтверждена
    INVALID     = 2,  // Команда получена, но не прошла проверку
    ERROR       = 3   // Невозможно определить состояние команды
};

class BKU
{
public:
    CommandStatus CheckCommand(bool commandReceived,
        bool checksumValid,
        bool communicationError)
    {
        if (communicationError)
            return CommandStatus::ERROR;

        if (!commandReceived)
            return CommandStatus::NO_COMMAND;

        if (!checksumValid)
            return CommandStatus::INVALID;

        return CommandStatus::VALID;
    }
};