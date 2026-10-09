enum class NavigationStatus : uint8_t
{
    NO_FIX       = 0, // Навигационное решение отсутствует
    VALID        = 1, // Решение получено, качество допустимое
    LOW_QUALITY  = 2, // Решение есть, но качество недостаточное
    ERROR        = 3  // Ошибка GNSS
};

class GNSS
{
public:
    NavigationStatus GetNavigationStatus(bool coordinatesAvailable,
        uint8_t satellitesCount,
        bool receiverError)
    {
        if (receiverError)
            return NavigationStatus::ERROR;

        if (!coordinatesAvailable)
            return NavigationStatus::NO_FIX;

        // Условно считаем, что для надёжного решения
        // необходимо не менее 4 спутников.
        if (satellitesCount < 4)
            return NavigationStatus::LOW_QUALITY;

        return NavigationStatus::VALID;
    }
};
