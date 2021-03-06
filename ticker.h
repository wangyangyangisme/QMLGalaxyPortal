/* Ticker thread
 *
 * Ticker lives in separate thread to be run in the background,
 * and every interval sends a tick to QML to perform background tasks.
 *
 */

#ifndef TICKER_H
#define TICKER_H

#include <QObject>

const int sleep_interval = 2; // Minimum sleep interval in seconds (tune this for performane).

class Ticker : public QObject
{
    Q_OBJECT
public:
    explicit Ticker(QObject *parent = 0);
    void setTickInterval(int interval);

private:
    int m_tickInterval;

signals:
    void tick();
    void exitThread();

public slots:
    void mainThread();


};

#endif // TICKER_H
