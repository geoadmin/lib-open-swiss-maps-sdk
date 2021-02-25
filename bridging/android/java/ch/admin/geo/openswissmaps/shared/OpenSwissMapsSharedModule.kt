// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from open_swiss_maps.djinni

package ch.admin.geo.openswissmaps.shared

import java.util.concurrent.atomic.AtomicBoolean

abstract class OpenSwissMapsSharedModule {

    companion object {
        @JvmStatic
        fun version(): String {
            return CppProxy.version()
        }
    }

    private class CppProxy : OpenSwissMapsSharedModule {
        private val nativeRef: Long
        private val destroyed: AtomicBoolean = AtomicBoolean(false)

        private constructor(nativeRef: Long) {
            if (nativeRef == 0L) error("nativeRef is zero")
            this.nativeRef = nativeRef
        }

        private external fun nativeDestroy(nativeRef: Long)
        fun _djinni_private_destroy() {
            val destroyed = this.destroyed.getAndSet(true)
            if (!destroyed) nativeDestroy(this.nativeRef)
        }
        protected fun finalize() {
            _djinni_private_destroy()
        }

        companion object {
            @JvmStatic
            external fun version(): String
        }
    }
}
