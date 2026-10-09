enum class BatteryState : uint8_t
{
    NORMAL   = 0, // Нормальный уровень заряда
        LOW      = 1, // Низкий уровень заряда
        CRITICAL = 2, // Критически низкий уровень
        UNKNOWN  = 3  // Состояние определить невозможно
};

class EPS
{
public:
    BatteryState GetBatteryState(float voltage,
        float chargePercent,
        bool telemetryValid)
    {
        if (!telemetryValid)
            return BatteryState::UNKNOWN;

        
        if (voltage < 20.0f || chargePercent < 10.0f)
            return BatteryState::CRITICAL;

        if (voltage < 24.0f || chargePercent < 30.0f)
            return BatteryState::LOW;

        return BatteryState::NORMAL;
    }
};
