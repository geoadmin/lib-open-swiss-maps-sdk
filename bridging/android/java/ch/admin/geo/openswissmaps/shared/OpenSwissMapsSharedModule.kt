// AUTOGENERATED FILE - DO NOT MODIFY!
// This file was generated by Djinni from open_swiss_maps.djinni

package ch.admin.geo.openswissmaps.shared

import com.snapchat.djinni.NativeObjectManager
import java.util.concurrent.atomic.AtomicBoolean

abstract class OpenSwissMapsSharedModule {

    companion object {
        @JvmStatic
        external fun version(): String
    }

    private class CppProxy : OpenSwissMapsSharedModule {
        private val nativeRef: Long
        private val destroyed: AtomicBoolean = AtomicBoolean(false)

        private constructor(nativeRef: Long) {
            if (nativeRef == 0L) error("nativeRef is zero")
            this.nativeRef = nativeRef
            NativeObjectManager.register(this, nativeRef)
        }

        companion object {
            @JvmStatic
            external fun nativeDestroy(nativeRef: Long)
        }
    }
}
