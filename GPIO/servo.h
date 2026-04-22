void DetectorInit(void);
enum DetectorState {ACTIVE, INACTIVE};
enum DetectorState eReadDetector(void);
void ServoInit(unsigned int uiServoFrequency);
void ServoCallib(void);
void ServoGoTo(unsigned int uiPosition);

void ServoHalt(unsigned int uiTime);