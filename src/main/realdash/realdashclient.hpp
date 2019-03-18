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

// Forward declarations
struct DBusConnection;

class RealDashCanClient
{
public:
    /** c'tor */
    RealDashCanClient();
    /** d'tor */
    ~RealDashCanClient();
    
    /** Update Rev Counter RPM */
    void updateRevs(uint16_t revsRpm);
    
    /** Update Speed MPH */
    void updateSpeed(uint16_t speedMph);
    
    /** Update Fuel Level % */
    void updateFuel(uint16_t fuelPercent);
    
    /** Update Gear */
    void updateGear(char gear);
    
private:
    void dbusMethodCallUint16(const char *methodName, uint16_t value);
    
private:
    DBusConnection *m_conn;
};

extern RealDashCanClient realDashCanClient;

#endif /* realdashclient_hpp */
