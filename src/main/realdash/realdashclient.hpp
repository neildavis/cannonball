//
//  realdashclient.hpp
//  cannonball
//
//  Created by Neil Davis on 17/03/2019.
//  See license.txt for more details.
//

#ifndef realdashclient_hpp
#define realdashclient_hpp

#include <stdint.h>

//
// Constants
//
/** Maximum revs */
extern const uint16_t RD_MAX_REVS_RPM;

// Forward declarations
struct DBusConnection;

class RealDashCanClient
{
public:
    /** c'tor */
    RealDashCanClient();
    /** d'tor */
    ~RealDashCanClient();
    
    /** Start CAN server */
    void startServer();
    
    /** Stop CAN server */
    void stopServer();

    /** Update Rev Counter RPM */
    void updateRevs(uint16_t revsRpm);
    
    /** Update Speed MPH */
    void updateSpeed(uint16_t speedMph);
    
    /** Update Fuel Level % */
    void updateFuel(uint16_t fuelPercent);
    
    /** Update Gear */
    void updateGear(char gear);
    
    /** Reset everything to default/zero states */
    void resetDefaults();
    
private:
    void dbusMethodCallSync(const char *methodName);
    void dbusMethodCallIgnoreReturn(const char *methodName, int type, const void *value);
    
private:
    DBusConnection *m_conn;
    // Internal cached data values
    uint16_t m_revsRpm;
    uint16_t m_speedMph;
    uint16_t m_fuelPercent;
    char m_gear;
};

extern RealDashCanClient realDashCanClient;

#endif /* realdashclient_hpp */
