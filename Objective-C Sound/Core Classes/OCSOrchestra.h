//
//  OCSOrchestra.h
//  Objective-C Sound
//
//  Created by Aurelius Prochazka on 5/30/12.
//  Copyright (c) 2012 Hear For Yourself. All rights reserved.
//

@class OCSInstrument;
@class OCSUserDefinedOperation;
@class OCSEvent;
@class OCSSequence;

/**OCSOrchestra is a collection of instruments and  handles all of the 
 CSD file creation tasks for the CSDManager.
 */
@interface OCSOrchestra : NSObject 

/// Determines the value from which to scale all other amplitudes in Csound
@property (nonatomic, assign) float zeroDBFullScaleValue;

/// The number of channels, ie. mono=1, stereo=2, hexaphonic=6.  Can affect both output and input.
@property (readonly) int numberOfChannels;

/// All the instruments in the orchestra, in order they need to be created.
@property (nonatomic, strong) NSMutableArray *instruments;


/// Adds an instrument to orchestra and informs the instrument which orchestra it now belongs to.
/// @param newInstrument Instrument that will be added to the orchestra.
- (void)addInstrument:(OCSInstrument *)newInstrument;

/// Adds the UDO to a set of required UDOs for the entire orchestra.
/// @param newUserDefinedOperation UDO to add to the orchestra.
- (void)addUDO:(OCSUserDefinedOperation *)newUserDefinedOperation;

/// @returns The complete CSD File representation for the orchestra including UDOs and instruments.
- (NSString *)stringForCSD;

@end