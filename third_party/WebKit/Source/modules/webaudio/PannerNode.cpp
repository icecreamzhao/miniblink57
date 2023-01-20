/*
 * Copyright (C) 2010, Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
<<<<<<< HEAD
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#include "modules/webaudio/PannerNode.h"
=======
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#if ENABLE(WEB_AUDIO)
#include "modules/webaudio/PannerNode.h"

>>>>>>> miniblink49
#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "modules/webaudio/AudioBufferSourceNode.h"
<<<<<<< HEAD
#include "modules/webaudio/AudioNodeInput.h"
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/BaseAudioContext.h"
#include "modules/webaudio/PannerOptions.h"
#include "platform/Histogram.h"
=======
#include "modules/webaudio/AudioContext.h"
#include "modules/webaudio/AudioNodeInput.h"
#include "modules/webaudio/AudioNodeOutput.h"
>>>>>>> miniblink49
#include "platform/audio/HRTFPanner.h"
#include "wtf/MathExtras.h"

namespace blink {

static void fixNANs(double& x)
{
<<<<<<< HEAD
    if (std_isnan(x) || std_isinf(x))
        x = 0.0;
}

PannerHandler::PannerHandler(AudioNode& node,
    float sampleRate,
    AudioParamHandler& positionX,
    AudioParamHandler& positionY,
    AudioParamHandler& positionZ,
    AudioParamHandler& orientationX,
    AudioParamHandler& orientationY,
    AudioParamHandler& orientationZ)
    : AudioHandler(NodeTypePanner, node, sampleRate)
    , m_listener(node.context()->listener())
    , m_distanceModel(DistanceEffect::ModelInverse)
    , m_isAzimuthElevationDirty(true)
    , m_isDistanceConeGainDirty(true)
=======
    if (std::isnan(x) || std::isinf(x))
        x = 0.0;
}

PannerHandler::PannerHandler(AudioNode& node, float sampleRate)
    : AudioHandler(NodeTypePanner, node, sampleRate)
    , m_listener(node.context()->listener())
    , m_panningModel(Panner::PanningModelEqualPower)
    , m_distanceModel(DistanceEffect::ModelInverse)
    , m_position(0, 0, 0)
    , m_orientation(1, 0, 0)
    , m_velocity(0, 0, 0)
    , m_isAzimuthElevationDirty(true)
    , m_isDistanceConeGainDirty(true)
    , m_isDopplerRateDirty(true)
>>>>>>> miniblink49
    , m_lastGain(-1.0)
    , m_cachedAzimuth(0)
    , m_cachedElevation(0)
    , m_cachedDistanceConeGain(1.0f)
<<<<<<< HEAD
    , m_positionX(positionX)
    , m_positionY(positionY)
    , m_positionZ(positionZ)
    , m_orientationX(orientationX)
    , m_orientationY(orientationY)
    , m_orientationZ(orientationZ)
{
=======
    , m_cachedDopplerRate(1)
{
    // Load the HRTF database asynchronously so we don't block the Javascript thread while creating the HRTF database.
    // The HRTF panner will return zeroes until the database is loaded.
    listener()->createAndLoadHRTFDatabaseLoader(node.context()->sampleRate());

>>>>>>> miniblink49
    addInput();
    addOutput(2);

    // Node-specific default mixing rules.
    m_channelCount = 2;
<<<<<<< HEAD
    setInternalChannelCountMode(ClampedMax);
    setInternalChannelInterpretation(AudioBus::Speakers);

    // Explicitly set the default panning model here so that the histograms
    // include the default value.
    setPanningModel("equalpower");
=======
    m_channelCountMode = ClampedMax;
    m_channelInterpretation = AudioBus::Speakers;
>>>>>>> miniblink49

    initialize();
}

<<<<<<< HEAD
PassRefPtr<PannerHandler> PannerHandler::create(
    AudioNode& node,
    float sampleRate,
    AudioParamHandler& positionX,
    AudioParamHandler& positionY,
    AudioParamHandler& positionZ,
    AudioParamHandler& orientationX,
    AudioParamHandler& orientationY,
    AudioParamHandler& orientationZ)
{
    return adoptRef(new PannerHandler(node, sampleRate, positionX, positionY,
        positionZ, orientationX, orientationY,
        orientationZ));
=======
PassRefPtr<PannerHandler> PannerHandler::create(AudioNode& node, float sampleRate)
{
    return adoptRef(new PannerHandler(node, sampleRate));
>>>>>>> miniblink49
}

PannerHandler::~PannerHandler()
{
    uninitialize();
}

void PannerHandler::process(size_t framesToProcess)
{
    AudioBus* destination = output(0).bus();

    if (!isInitialized() || !input(0).isConnected() || !m_panner.get()) {
        destination->zero();
        return;
    }

    AudioBus* source = input(0).bus();
    if (!source) {
        destination->zero();
        return;
    }

    // The audio thread can't block on this lock, so we call tryLock() instead.
    MutexTryLocker tryLocker(m_processLock);
    MutexTryLocker tryListenerLocker(listener()->listenerLock());

    if (tryLocker.locked() && tryListenerLocker.locked()) {
<<<<<<< HEAD
        if (!context()->hasRealtimeConstraint() && m_panningModel == Panner::PanningModelHRTF) {
            // For an OfflineAudioContext, we need to make sure the HRTFDatabase
            // is loaded before proceeding.  For realtime contexts, we don't
            // have to wait.  The HRTF panner handles that case itself.
            listener()->waitForHRTFDatabaseLoaderThreadCompletion();
        }

        if (hasSampleAccurateValues() || listener()->hasSampleAccurateValues()) {
            // It's tempting to skip sample-accurate processing if
            // isAzimuthElevationDirty() and isDistanceConeGain() both return false.
            // But in general we can't because something may scheduled to start in the
            // middle of the rendering quantum.  On the other hand, the audible effect
            // may be small enough that we can afford to do this optimization.
            processSampleAccurateValues(destination, source, framesToProcess);
        } else {
            // Apply the panning effect.
            double azimuth;
            double elevation;

            // Update dirty state in case something has moved; this can happen if the
            // AudioParam for the position or orientation component is set directly.
            updateDirtyState();

            azimuthElevation(&azimuth, &elevation);

            m_panner->pan(azimuth, elevation, source, destination, framesToProcess,
                internalChannelInterpretation());

            // Get the distance and cone gain.
            float totalGain = distanceConeGain();

            m_lastGain = totalGain;

            // Apply gain in-place with de-zippering.
            destination->copyWithGainFrom(*destination, &m_lastGain, totalGain);
        }
    } else {
        // Too bad - The tryLock() failed.  We must be in the middle of changing the
        // properties of the panner or the listener.
=======
        // HRTFDatabase should be loaded before proceeding for offline audio context when the panning model is HRTF.
        if (m_panningModel == Panner::PanningModelHRTF && !listener()->isHRTFDatabaseLoaded()) {
            if (context()->isOfflineContext()) {
                listener()->waitForHRTFDatabaseLoaderThreadCompletion();
            } else {
                destination->zero();
                return;
            }
        }

        // Apply the panning effect.
        double azimuth;
        double elevation;
        azimuthElevation(&azimuth, &elevation);

        m_panner->pan(azimuth, elevation, source, destination, framesToProcess);

        // Get the distance and cone gain.
        float totalGain = distanceConeGain();

        // Snap to desired gain at the beginning.
        if (m_lastGain == -1.0)
            m_lastGain = totalGain;

        // Apply gain in-place with de-zippering.
        destination->copyWithGainFrom(*destination, &m_lastGain, totalGain);
    } else {
        // Too bad - The tryLock() failed.
        // We must be in the middle of changing the properties of the panner or the listener.
>>>>>>> miniblink49
        destination->zero();
    }
}

<<<<<<< HEAD
void PannerHandler::processSampleAccurateValues(AudioBus* destination,
    const AudioBus* source,
    size_t framesToProcess)
{
    RELEASE_ASSERT(framesToProcess <= AudioUtilities::kRenderQuantumFrames);

    // Get the sample accurate values from all of the AudioParams, including the
    // values from the AudioListener.
    float pannerX[AudioUtilities::kRenderQuantumFrames];
    float pannerY[AudioUtilities::kRenderQuantumFrames];
    float pannerZ[AudioUtilities::kRenderQuantumFrames];

    float orientationX[AudioUtilities::kRenderQuantumFrames];
    float orientationY[AudioUtilities::kRenderQuantumFrames];
    float orientationZ[AudioUtilities::kRenderQuantumFrames];

    m_positionX->calculateSampleAccurateValues(pannerX, framesToProcess);
    m_positionY->calculateSampleAccurateValues(pannerY, framesToProcess);
    m_positionZ->calculateSampleAccurateValues(pannerZ, framesToProcess);
    m_orientationX->calculateSampleAccurateValues(orientationX, framesToProcess);
    m_orientationY->calculateSampleAccurateValues(orientationY, framesToProcess);
    m_orientationZ->calculateSampleAccurateValues(orientationZ, framesToProcess);

    // Get the automation values from the listener.
    const float* listenerX = listener()->getPositionXValues(AudioUtilities::kRenderQuantumFrames);
    const float* listenerY = listener()->getPositionYValues(AudioUtilities::kRenderQuantumFrames);
    const float* listenerZ = listener()->getPositionZValues(AudioUtilities::kRenderQuantumFrames);

    const float* forwardX = listener()->getForwardXValues(AudioUtilities::kRenderQuantumFrames);
    const float* forwardY = listener()->getForwardYValues(AudioUtilities::kRenderQuantumFrames);
    const float* forwardZ = listener()->getForwardZValues(AudioUtilities::kRenderQuantumFrames);

    const float* upX = listener()->getUpXValues(AudioUtilities::kRenderQuantumFrames);
    const float* upY = listener()->getUpYValues(AudioUtilities::kRenderQuantumFrames);
    const float* upZ = listener()->getUpZValues(AudioUtilities::kRenderQuantumFrames);

    // Compute the azimuth, elevation, and total gains for each position.
    double azimuth[AudioUtilities::kRenderQuantumFrames];
    double elevation[AudioUtilities::kRenderQuantumFrames];
    float totalGain[AudioUtilities::kRenderQuantumFrames];

    for (unsigned k = 0; k < framesToProcess; ++k) {
        FloatPoint3D pannerPosition(pannerX[k], pannerY[k], pannerZ[k]);
        FloatPoint3D orientation(orientationX[k], orientationY[k], orientationZ[k]);
        FloatPoint3D listenerPosition(listenerX[k], listenerY[k], listenerZ[k]);
        FloatPoint3D listenerForward(forwardX[k], forwardY[k], forwardZ[k]);
        FloatPoint3D listenerUp(upX[k], upY[k], upZ[k]);

        calculateAzimuthElevation(&azimuth[k], &elevation[k], pannerPosition,
            listenerPosition, listenerForward, listenerUp);

        // Get distance and cone gain
        totalGain[k] = calculateDistanceConeGain(pannerPosition, orientation,
            listenerPosition);
    }

    m_panner->panWithSampleAccurateValues(azimuth, elevation, source, destination,
        framesToProcess,
        internalChannelInterpretation());
    destination->copyWithSampleAccurateGainValuesFrom(*destination, totalGain,
        framesToProcess);
}

void PannerHandler::processOnlyAudioParams(size_t framesToProcess)
{
    float values[AudioUtilities::kRenderQuantumFrames];

    DCHECK_LE(framesToProcess, AudioUtilities::kRenderQuantumFrames);

    m_positionX->calculateSampleAccurateValues(values, framesToProcess);
    m_positionY->calculateSampleAccurateValues(values, framesToProcess);
    m_positionZ->calculateSampleAccurateValues(values, framesToProcess);

    m_orientationX->calculateSampleAccurateValues(values, framesToProcess);
    m_orientationY->calculateSampleAccurateValues(values, framesToProcess);
    m_orientationZ->calculateSampleAccurateValues(values, framesToProcess);
}

=======
>>>>>>> miniblink49
void PannerHandler::initialize()
{
    if (isInitialized())
        return;

<<<<<<< HEAD
    m_panner = Panner::create(m_panningModel, sampleRate(),
        listener()->hrtfDatabaseLoader());
    listener()->addPanner(*this);

    // Set the cached values to the current values to start things off.  The
    // panner is already marked as dirty, so this won't matter.
    m_lastPosition = position();
    m_lastOrientation = orientation();

=======
    m_panner = Panner::create(m_panningModel, sampleRate(), listener()->hrtfDatabaseLoader());
    listener()->addPanner(*this);

>>>>>>> miniblink49
    AudioHandler::initialize();
}

void PannerHandler::uninitialize()
{
    if (!isInitialized())
        return;

<<<<<<< HEAD
    m_panner.reset();
=======
    m_panner.clear();
>>>>>>> miniblink49
    listener()->removePanner(*this);

    AudioHandler::uninitialize();
}

AudioListener* PannerHandler::listener()
{
    return m_listener;
}

String PannerHandler::panningModel() const
{
    switch (m_panningModel) {
    case Panner::PanningModelEqualPower:
        return "equalpower";
    case Panner::PanningModelHRTF:
        return "HRTF";
    default:
        ASSERT_NOT_REACHED();
        return "equalpower";
    }
}

void PannerHandler::setPanningModel(const String& model)
{
<<<<<<< HEAD
    // WebIDL should guarantee that we are never called with an invalid string
    // for the model.
=======
>>>>>>> miniblink49
    if (model == "equalpower")
        setPanningModel(Panner::PanningModelEqualPower);
    else if (model == "HRTF")
        setPanningModel(Panner::PanningModelHRTF);
<<<<<<< HEAD
    else
        NOTREACHED();
}

// This method should only be called from setPanningModel(const String&)!
bool PannerHandler::setPanningModel(unsigned model)
{
    DEFINE_STATIC_LOCAL(EnumerationHistogram, panningModelHistogram,
        ("WebAudio.PannerNode.PanningModel", 2));
    panningModelHistogram.count(model);

    if (model == Panner::PanningModelHRTF) {
        // Load the HRTF database asynchronously so we don't block the
        // Javascript thread while creating the HRTF database. It's ok to call
        // this multiple times; we won't be constantly loading the database over
        // and over.
        listener()->createAndLoadHRTFDatabaseLoader(context()->sampleRate());
    }

    if (!m_panner.get() || model != m_panningModel) {
        // This synchronizes with process().
        MutexLocker processLocker(m_processLock);
        m_panner = Panner::create(model, sampleRate(), listener()->hrtfDatabaseLoader());
        m_panningModel = model;
    }
=======
}

bool PannerHandler::setPanningModel(unsigned model)
{
    switch (model) {
    case Panner::PanningModelEqualPower:
    case Panner::PanningModelHRTF:
        if (!m_panner.get() || model != m_panningModel) {
            // This synchronizes with process().
            MutexLocker processLocker(m_processLock);
            m_panner = Panner::create(model, sampleRate(), listener()->hrtfDatabaseLoader());
            m_panningModel = model;
        }
        break;
    default:
        ASSERT_NOT_REACHED();
        return false;
    }

>>>>>>> miniblink49
    return true;
}

String PannerHandler::distanceModel() const
{
    switch (const_cast<PannerHandler*>(this)->m_distanceEffect.model()) {
    case DistanceEffect::ModelLinear:
        return "linear";
    case DistanceEffect::ModelInverse:
        return "inverse";
    case DistanceEffect::ModelExponential:
        return "exponential";
    default:
        ASSERT_NOT_REACHED();
        return "inverse";
    }
}

void PannerHandler::setDistanceModel(const String& model)
{
    if (model == "linear")
        setDistanceModel(DistanceEffect::ModelLinear);
    else if (model == "inverse")
        setDistanceModel(DistanceEffect::ModelInverse);
    else if (model == "exponential")
        setDistanceModel(DistanceEffect::ModelExponential);
}

bool PannerHandler::setDistanceModel(unsigned model)
{
    switch (model) {
    case DistanceEffect::ModelLinear:
    case DistanceEffect::ModelInverse:
    case DistanceEffect::ModelExponential:
        if (model != m_distanceModel) {
            // This synchronizes with process().
            MutexLocker processLocker(m_processLock);
<<<<<<< HEAD
            m_distanceEffect.setModel(
                static_cast<DistanceEffect::ModelType>(model));
=======
            m_distanceEffect.setModel(static_cast<DistanceEffect::ModelType>(model), true);
>>>>>>> miniblink49
            m_distanceModel = model;
        }
        break;
    default:
        ASSERT_NOT_REACHED();
        return false;
    }

    return true;
}

void PannerHandler::setRefDistance(double distance)
{
    if (refDistance() == distance)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_distanceEffect.setRefDistance(distance);
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setMaxDistance(double distance)
{
    if (maxDistance() == distance)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_distanceEffect.setMaxDistance(distance);
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setRolloffFactor(double factor)
{
    if (rolloffFactor() == factor)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_distanceEffect.setRolloffFactor(factor);
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setConeInnerAngle(double angle)
{
    if (coneInnerAngle() == angle)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_coneEffect.setInnerAngle(angle);
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setConeOuterAngle(double angle)
{
    if (coneOuterAngle() == angle)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_coneEffect.setOuterAngle(angle);
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setConeOuterGain(double angle)
{
    if (coneOuterGain() == angle)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_coneEffect.setOuterGain(angle);
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setPosition(float x, float y, float z)
{
<<<<<<< HEAD
    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);

    m_positionX->setValue(x);
    m_positionY->setValue(y);
    m_positionZ->setValue(z);

    markPannerAsDirty(PannerHandler::AzimuthElevationDirty | PannerHandler::DistanceConeGainDirty);
=======
    FloatPoint3D position = FloatPoint3D(x, y, z);

    if (m_position == position)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_position = position;
    markPannerAsDirty(PannerHandler::AzimuthElevationDirty | PannerHandler::DistanceConeGainDirty | PannerHandler::DopplerRateDirty);
>>>>>>> miniblink49
}

void PannerHandler::setOrientation(float x, float y, float z)
{
<<<<<<< HEAD
    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);

    m_orientationX->setValue(x);
    m_orientationY->setValue(y);
    m_orientationZ->setValue(z);

    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::calculateAzimuthElevation(
    double* outAzimuth,
    double* outElevation,
    const FloatPoint3D& position,
    const FloatPoint3D& listenerPosition,
    const FloatPoint3D& listenerForward,
    const FloatPoint3D& listenerUp)
=======
    FloatPoint3D orientation = FloatPoint3D(x, y, z);

    if (m_orientation == orientation)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_orientation = orientation;
    markPannerAsDirty(PannerHandler::DistanceConeGainDirty);
}

void PannerHandler::setVelocity(float x, float y, float z)
{
    FloatPoint3D velocity = FloatPoint3D(x, y, z);

    if (m_velocity == velocity)
        return;

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_velocity = velocity;
    markPannerAsDirty(PannerHandler::DopplerRateDirty);
}

void PannerHandler::calculateAzimuthElevation(double* outAzimuth, double* outElevation)
>>>>>>> miniblink49
{
    double azimuth = 0.0;

    // Calculate the source-listener vector
<<<<<<< HEAD
    FloatPoint3D sourceListener = position - listenerPosition;
=======
    FloatPoint3D listenerPosition = listener()->position();
    FloatPoint3D sourceListener = m_position - listenerPosition;
>>>>>>> miniblink49

    // normalize() does nothing if the length of |sourceListener| is zero.
    sourceListener.normalize();

    // Align axes
<<<<<<< HEAD
    FloatPoint3D listenerRight = listenerForward.cross(listenerUp);
    listenerRight.normalize();

    FloatPoint3D listenerForwardNorm = listenerForward;
    listenerForwardNorm.normalize();

    FloatPoint3D up = listenerRight.cross(listenerForwardNorm);
=======
    FloatPoint3D listenerFront = listener()->orientation();
    FloatPoint3D listenerUp = listener()->upVector();
    FloatPoint3D listenerRight = listenerFront.cross(listenerUp);
    listenerRight.normalize();

    FloatPoint3D listenerFrontNorm = listenerFront;
    listenerFrontNorm.normalize();

    FloatPoint3D up = listenerRight.cross(listenerFrontNorm);
>>>>>>> miniblink49

    float upProjection = sourceListener.dot(up);

    FloatPoint3D projectedSource = sourceListener - upProjection * up;

    azimuth = rad2deg(projectedSource.angleBetween(listenerRight));
    fixNANs(azimuth); // avoid illegal values

    // Source  in front or behind the listener
<<<<<<< HEAD
    double frontBack = projectedSource.dot(listenerForwardNorm);
=======
    double frontBack = projectedSource.dot(listenerFrontNorm);
>>>>>>> miniblink49
    if (frontBack < 0.0)
        azimuth = 360.0 - azimuth;

    // Make azimuth relative to "front" and not "right" listener vector
    if ((azimuth >= 0.0) && (azimuth <= 270.0))
        azimuth = 90.0 - azimuth;
    else
        azimuth = 450.0 - azimuth;

    // Elevation
    double elevation = 90 - rad2deg(sourceListener.angleBetween(up));
    fixNANs(elevation); // avoid illegal values

    if (elevation > 90.0)
        elevation = 180.0 - elevation;
    else if (elevation < -90.0)
        elevation = -180.0 - elevation;

    if (outAzimuth)
        *outAzimuth = azimuth;
    if (outElevation)
        *outElevation = elevation;
}

<<<<<<< HEAD
float PannerHandler::calculateDistanceConeGain(
    const FloatPoint3D& position,
    const FloatPoint3D& orientation,
    const FloatPoint3D& listenerPosition)
{
    double listenerDistance = position.distanceTo(listenerPosition);
    double distanceGain = m_distanceEffect.gain(listenerDistance);
    double coneGain = m_coneEffect.gain(position, orientation, listenerPosition);
=======
double PannerHandler::calculateDopplerRate()
{
    double dopplerShift = 1.0;
    double dopplerFactor = listener()->dopplerFactor();

    if (dopplerFactor > 0.0) {
        double speedOfSound = listener()->speedOfSound();

        const FloatPoint3D& sourceVelocity = m_velocity;
        const FloatPoint3D& listenerVelocity = listener()->velocity();

        // Don't bother if both source and listener have no velocity
        bool sourceHasVelocity = !sourceVelocity.isZero();
        bool listenerHasVelocity = !listenerVelocity.isZero();

        if (sourceHasVelocity || listenerHasVelocity) {
            // Calculate the source to listener vector
            FloatPoint3D listenerPosition = listener()->position();
            FloatPoint3D sourceToListener = m_position - listenerPosition;

            double sourceListenerMagnitude = sourceToListener.length();

            if (!sourceListenerMagnitude) {
                // Source and listener are at the same position. Skip the computation of the doppler
                // shift, and just return the cached value.
                dopplerShift = m_cachedDopplerRate;
            } else {
                double listenerProjection = sourceToListener.dot(listenerVelocity) / sourceListenerMagnitude;
                double sourceProjection = sourceToListener.dot(sourceVelocity) / sourceListenerMagnitude;

                listenerProjection = -listenerProjection;
                sourceProjection = -sourceProjection;

                double scaledSpeedOfSound = speedOfSound / dopplerFactor;
                listenerProjection = std::min(listenerProjection, scaledSpeedOfSound);
                sourceProjection = std::min(sourceProjection, scaledSpeedOfSound);

                dopplerShift = ((speedOfSound - dopplerFactor * listenerProjection) / (speedOfSound - dopplerFactor * sourceProjection));
                fixNANs(dopplerShift); // avoid illegal values

                // Limit the pitch shifting to 4 octaves up and 3 octaves down.
                if (dopplerShift > 16.0)
                    dopplerShift = 16.0;
                else if (dopplerShift < 0.125)
                    dopplerShift = 0.125;
            }
        }
    }

    return dopplerShift;
}

float PannerHandler::calculateDistanceConeGain()
{
    FloatPoint3D listenerPosition = listener()->position();

    double listenerDistance = m_position.distanceTo(listenerPosition);
    double distanceGain = m_distanceEffect.gain(listenerDistance);
    double coneGain = m_coneEffect.gain(m_position, m_orientation, listenerPosition);
>>>>>>> miniblink49

    return float(distanceGain * coneGain);
}

void PannerHandler::azimuthElevation(double* outAzimuth, double* outElevation)
{
<<<<<<< HEAD
    DCHECK(context()->isAudioThread());

    // Calculate new azimuth and elevation if the panner or the listener changed
    // position or orientation in any way.
    if (isAzimuthElevationDirty() || listener()->isListenerDirty()) {
        calculateAzimuthElevation(&m_cachedAzimuth, &m_cachedElevation, position(),
            listener()->position(), listener()->orientation(),
            listener()->upVector());
=======
    ASSERT(context()->isAudioThread());

    if (isAzimuthElevationDirty()) {
        calculateAzimuthElevation(&m_cachedAzimuth, &m_cachedElevation);
>>>>>>> miniblink49
        m_isAzimuthElevationDirty = false;
    }

    *outAzimuth = m_cachedAzimuth;
    *outElevation = m_cachedElevation;
}

<<<<<<< HEAD
float PannerHandler::distanceConeGain()
{
    DCHECK(context()->isAudioThread());

    // Calculate new distance and cone gain if the panner or the listener
    // changed position or orientation in any way.
    if (isDistanceConeGainDirty() || listener()->isListenerDirty()) {
        m_cachedDistanceConeGain = calculateDistanceConeGain(
            position(), orientation(), listener()->position());
=======
double PannerHandler::dopplerRate()
{
    ASSERT(context()->isAudioThread());

    if (isDopplerRateDirty()) {
        m_cachedDopplerRate = calculateDopplerRate();
        m_isDopplerRateDirty = false;
    }

    return m_cachedDopplerRate;
}

float PannerHandler::distanceConeGain()
{
    ASSERT(context()->isAudioThread());

    if (isDistanceConeGainDirty()) {
        m_cachedDistanceConeGain = calculateDistanceConeGain();
>>>>>>> miniblink49
        m_isDistanceConeGainDirty = false;
    }

    return m_cachedDistanceConeGain;
}

void PannerHandler::markPannerAsDirty(unsigned dirty)
{
    if (dirty & PannerHandler::AzimuthElevationDirty)
        m_isAzimuthElevationDirty = true;

    if (dirty & PannerHandler::DistanceConeGainDirty)
        m_isDistanceConeGainDirty = true;
<<<<<<< HEAD
}

void PannerHandler::setChannelCount(unsigned long channelCount,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());
    BaseAudioContext::AutoLocker locker(context());
=======

    if (dirty & PannerHandler::DopplerRateDirty)
        m_isDopplerRateDirty = true;
}

void PannerHandler::setChannelCount(unsigned long channelCount, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());
    AudioContext::AutoLocker locker(context());
>>>>>>> miniblink49

    // A PannerNode only supports 1 or 2 channels
    if (channelCount > 0 && channelCount <= 2) {
        if (m_channelCount != channelCount) {
            m_channelCount = channelCount;
<<<<<<< HEAD
            if (internalChannelCountMode() != Max)
=======
            if (m_channelCountMode != Max)
>>>>>>> miniblink49
                updateChannelsForInputs();
        }
    } else {
        exceptionState.throwDOMException(
            NotSupportedError,
            ExceptionMessages::indexOutsideRange<unsigned long>(
<<<<<<< HEAD
                "channelCount", channelCount, 1, ExceptionMessages::InclusiveBound,
                2, ExceptionMessages::InclusiveBound));
    }
}

void PannerHandler::setChannelCountMode(const String& mode,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());
    BaseAudioContext::AutoLocker locker(context());

    ChannelCountMode oldMode = internalChannelCountMode();
=======
                "channelCount",
                channelCount,
                1,
                ExceptionMessages::InclusiveBound,
                2,
                ExceptionMessages::InclusiveBound));
    }
}

void PannerHandler::setChannelCountMode(const String& mode, ExceptionState& exceptionState)
{
    ASSERT(isMainThread());
    AudioContext::AutoLocker locker(context());

    ChannelCountMode oldMode = m_channelCountMode;
>>>>>>> miniblink49

    if (mode == "clamped-max") {
        m_newChannelCountMode = ClampedMax;
    } else if (mode == "explicit") {
        m_newChannelCountMode = Explicit;
    } else if (mode == "max") {
<<<<<<< HEAD
        // This is not supported for a PannerNode, which can only handle 1 or 2
        // channels.
        exceptionState.throwDOMException(NotSupportedError,
            "Panner: 'max' is not allowed");
=======
        // This is not supported for a PannerNode, which can only handle 1 or 2 channels.
        exceptionState.throwDOMException(
            NotSupportedError,
                "Panner: 'max' is not allowed");
>>>>>>> miniblink49
        m_newChannelCountMode = oldMode;
    } else {
        // Do nothing for other invalid values.
        m_newChannelCountMode = oldMode;
    }

    if (m_newChannelCountMode != oldMode)
        context()->deferredTaskHandler().addChangedChannelCountMode(this);
}

<<<<<<< HEAD
bool PannerHandler::hasSampleAccurateValues() const
{
    return m_positionX->hasSampleAccurateValues() || m_positionY->hasSampleAccurateValues() || m_positionZ->hasSampleAccurateValues() || m_orientationX->hasSampleAccurateValues() || m_orientationY->hasSampleAccurateValues() || m_orientationZ->hasSampleAccurateValues();
}

void PannerHandler::updateDirtyState()
{
    DCHECK(context()->isAudioThread());

    FloatPoint3D currentPosition = position();
    FloatPoint3D currentOrientation = orientation();

    bool hasMoved = currentPosition != m_lastPosition || currentOrientation != m_lastOrientation;

    if (hasMoved) {
        m_lastPosition = currentPosition;
        m_lastOrientation = currentOrientation;

        markPannerAsDirty(PannerHandler::AzimuthElevationDirty | PannerHandler::DistanceConeGainDirty);
    }
}
// ----------------------------------------------------------------

PannerNode::PannerNode(BaseAudioContext& context)
    : AudioNode(context)
    , m_positionX(AudioParam::create(context, ParamTypePannerPositionX, 0.0))
    , m_positionY(AudioParam::create(context, ParamTypePannerPositionY, 0.0))
    , m_positionZ(AudioParam::create(context, ParamTypePannerPositionZ, 0.0))
    , m_orientationX(
          AudioParam::create(context, ParamTypePannerOrientationX, 1.0))
    , m_orientationY(
          AudioParam::create(context, ParamTypePannerOrientationY, 0.0))
    , m_orientationZ(
          AudioParam::create(context, ParamTypePannerOrientationZ, 0.0))
{
    setHandler(PannerHandler::create(
        *this, context.sampleRate(), m_positionX->handler(),
        m_positionY->handler(), m_positionZ->handler(), m_orientationX->handler(),
        m_orientationY->handler(), m_orientationZ->handler()));
}

PannerNode* PannerNode::create(BaseAudioContext& context,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (context.isContextClosed()) {
        context.throwExceptionForClosedState(exceptionState);
        return nullptr;
    }

    return new PannerNode(context);
}

PannerNode* PannerNode::create(BaseAudioContext* context,
    const PannerOptions& options,
    ExceptionState& exceptionState)
{
    PannerNode* node = create(*context, exceptionState);

    if (!node)
        return nullptr;

    node->handleChannelOptions(options, exceptionState);

    if (options.hasPanningModel())
        node->setPanningModel(options.panningModel());
    if (options.hasDistanceModel())
        node->setDistanceModel(options.distanceModel());

    if (options.hasPositionX())
        node->positionX()->setValue(options.positionX());
    if (options.hasPositionY())
        node->positionY()->setValue(options.positionY());
    if (options.hasPositionZ())
        node->positionZ()->setValue(options.positionZ());

    if (options.hasOrientationX())
        node->orientationX()->setValue(options.orientationX());
    if (options.hasOrientationY())
        node->orientationY()->setValue(options.orientationY());
    if (options.hasOrientationZ())
        node->orientationZ()->setValue(options.orientationZ());

    if (options.hasRefDistance())
        node->setRefDistance(options.refDistance(), exceptionState);
    if (options.hasMaxDistance())
        node->setMaxDistance(options.maxDistance(), exceptionState);
    if (options.hasRolloffFactor())
        node->setRolloffFactor(options.rolloffFactor());
    if (options.hasConeInnerAngle())
        node->setConeInnerAngle(options.coneInnerAngle());
    if (options.hasConeOuterAngle())
        node->setConeOuterAngle(options.coneOuterAngle());
    if (options.hasConeOuterGain())
        node->setConeOuterGain(options.coneOuterGain());

    return node;
=======
// ----------------------------------------------------------------

PannerNode::PannerNode(AudioContext& context, float sampelRate)
    : AudioNode(context)
{
    setHandler(PannerHandler::create(*this, sampelRate));
}

PannerNode* PannerNode::create(AudioContext& context, float sampleRate)
{
    return new PannerNode(context, sampleRate);
>>>>>>> miniblink49
}

PannerHandler& PannerNode::pannerHandler() const
{
    return static_cast<PannerHandler&>(handler());
}

String PannerNode::panningModel() const
{
    return pannerHandler().panningModel();
}

void PannerNode::setPanningModel(const String& model)
{
    pannerHandler().setPanningModel(model);
}

void PannerNode::setPosition(float x, float y, float z)
{
    pannerHandler().setPosition(x, y, z);
}

void PannerNode::setOrientation(float x, float y, float z)
{
    pannerHandler().setOrientation(x, y, z);
}

<<<<<<< HEAD
=======
void PannerNode::setVelocity(float x, float y, float z)
{
    pannerHandler().setVelocity(x, y, z);
}

>>>>>>> miniblink49
String PannerNode::distanceModel() const
{
    return pannerHandler().distanceModel();
}

void PannerNode::setDistanceModel(const String& model)
{
    pannerHandler().setDistanceModel(model);
}

double PannerNode::refDistance() const
{
    return pannerHandler().refDistance();
}

<<<<<<< HEAD
void PannerNode::setRefDistance(double distance,
    ExceptionState& exceptionState)
{
    if (distance <= 0) {
        exceptionState.throwDOMException(
            V8RangeError, ExceptionMessages::indexExceedsMinimumBound<double>("refDistance", distance, 0));
        return;
    }

=======
void PannerNode::setRefDistance(double distance)
{
>>>>>>> miniblink49
    pannerHandler().setRefDistance(distance);
}

double PannerNode::maxDistance() const
{
    return pannerHandler().maxDistance();
}

<<<<<<< HEAD
void PannerNode::setMaxDistance(double distance,
    ExceptionState& exceptionState)
{
    if (distance <= 0) {
        exceptionState.throwDOMException(
            V8RangeError, ExceptionMessages::indexExceedsMinimumBound<double>("maxDistance", distance, 0));
        return;
    }

=======
void PannerNode::setMaxDistance(double distance)
{
>>>>>>> miniblink49
    pannerHandler().setMaxDistance(distance);
}

double PannerNode::rolloffFactor() const
{
    return pannerHandler().rolloffFactor();
}

void PannerNode::setRolloffFactor(double factor)
{
    pannerHandler().setRolloffFactor(factor);
}

double PannerNode::coneInnerAngle() const
{
    return pannerHandler().coneInnerAngle();
}

void PannerNode::setConeInnerAngle(double angle)
{
    pannerHandler().setConeInnerAngle(angle);
}

double PannerNode::coneOuterAngle() const
{
    return pannerHandler().coneOuterAngle();
}

void PannerNode::setConeOuterAngle(double angle)
{
    pannerHandler().setConeOuterAngle(angle);
}

double PannerNode::coneOuterGain() const
{
    return pannerHandler().coneOuterGain();
}

void PannerNode::setConeOuterGain(double gain)
{
    pannerHandler().setConeOuterGain(gain);
}

<<<<<<< HEAD
DEFINE_TRACE(PannerNode)
{
    visitor->trace(m_positionX);
    visitor->trace(m_positionY);
    visitor->trace(m_positionZ);

    visitor->trace(m_orientationX);
    visitor->trace(m_orientationY);
    visitor->trace(m_orientationZ);

    AudioNode::trace(visitor);
}

} // namespace blink
=======
} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
