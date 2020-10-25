
#include "STD_TYPES.h"
#include "TIMER_interface.h"
#include "TIMER_config.h"


/** Timer configurations table **/
const TIMER_config_t configTable[TIMER_NUMBER] = {
//   Timer      Timer        Timer          Interrupt    CLK         Prescaller       Interval
//   channel	enable       mode           enable       source                       in US
	{TIM1    ,  DISABLE     , UP_COUNTER    , DISABLE    , APB2_CLK    , 128            , 0 } ,
	{TIM2    ,  ENABLE    , UP_COUNTER    , ENABLE    , APB1_CLK    , 8              , 2 } ,
	{TIM3    ,  DISABLE     , UP_COUNTER    , DISABLE    , APB1_CLK    , 128            , 0 } ,
	{TIM4    ,  DISABLE     , UP_COUNTER    , DISABLE    , APB1_CLK    , 128            , 0 }
};
