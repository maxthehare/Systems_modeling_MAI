enum class SensorStatus : uint8_t
{
    OK             = 0, // Датчик исправен
    OUT_OF_RANGE   = 1, // Значение вне физически допустимого диапазона
    DATA_OUTDATED  = 2, // Данные устарели
    ERROR          = 3  // Нет связи с датчиком
};

class Thermal
{
public:
    SensorStatus GetSensorStatus(float temperature,
        uint32_t dataAgeMs,
        bool communicationError)
    {
        if (communicationError)
            return SensorStatus::ERROR;

        // Условный допустимый физический диапазон датчика.
        if (temperature < -100.0f || temperature > 150.0f)
            return SensorStatus::OUT_OF_RANGE;

        // Если данные старше пяти секунд, считаем их устаревшими.
        if (dataAgeMs > 5000)
            return SensorStatus::DATA_OUTDATED;

        return SensorStatus::OK;
    }
};
