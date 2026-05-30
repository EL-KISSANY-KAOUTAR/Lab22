#include <jni.h>
#include <string>
#include <algorithm>
#include <android/log.h>

#define LOG_TAG "NEXUS_NATIVE"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_projet_fst_ma_jnidemo_MainActivity_obtenirMessageNexus(
        JNIEnv* env, jobject /* this */) {
    LOGI("Nexus Core: Statut demandé");
    return env->NewStringUTF("Noyau Nexus C++ : Opérationnel");
}

extern "C"
JNIEXPORT jint JNICALL
Java_projet_fst_ma_jnidemo_MainActivity_calculerFactorielleNexus(
        JNIEnv* env, jobject /* this */, jint n) {
    if (n < 0) return -1;
    long long res = 1;
    for (int i = 1; i <= n; i++) res *= i;
    LOGI("Nexus Core: Calcul factoriel terminé");
    return static_cast<jint>(res);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_projet_fst_ma_jnidemo_MainActivity_inverserTexteNexus(
        JNIEnv* env, jobject /* this */, jstring input) {
    if (input == nullptr) return nullptr;
    const char* nativeString = env->GetStringUTFChars(input, nullptr);
    std::string s(nativeString);
    env->ReleaseStringUTFChars(input, nativeString);
    std::reverse(s.begin(), s.end());
    LOGI("Nexus Core: Inversion de texte terminée");
    return env->NewStringUTF(s.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_projet_fst_ma_jnidemo_MainActivity_sommerDonneesNexus(
        JNIEnv* env, jobject /* this */, jintArray arr) {
    if (arr == nullptr) return 0;
    jsize len = env->GetArrayLength(arr);
    jint* elements = env->GetIntArrayElements(arr, nullptr);
    long long sum = 0;
    for (jsize i = 0; i < len; i++) sum += elements[i];
    env->ReleaseIntArrayElements(arr, elements, 0);
    LOGI("Nexus Core: Somme de données terminée");
    return static_cast<jint>(sum);
}