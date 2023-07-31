/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/ShadowNodeTraits.h>

namespace facebook::react::ViewTraitsInitializer {

static bool formsStackingContext(ViewProps const &viewProps) {
  return viewProps.elevation != 0;
}

static bool formsView(ViewProps const &viewProps) {
  return viewProps.nativeBackground.has_value() ||
      viewProps.nativeForeground.has_value() || viewProps.focusable ||
      viewProps.hasTVPreferredFocus ||
      viewProps.needsOffscreenAlphaCompositing ||
      viewProps.renderToHardwareTextureAndroid;
}

static ShadowNodeTraits::Trait extraTraits() {
  return ShadowNodeTraits::Trait::AndroidMapBufferPropsSupported;
}

} // namespace facebook::react::ViewTraitsInitializer