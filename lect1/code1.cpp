class Muchness {
  public:
    void setCurLevel(float cur);
    float getCurLevel();
    void setThresholdLevel(float cur);
    float getThresholdLevel(); 
    bool isItTooMuch();
  private:
    float curLevel, thresholdLevel;
};
