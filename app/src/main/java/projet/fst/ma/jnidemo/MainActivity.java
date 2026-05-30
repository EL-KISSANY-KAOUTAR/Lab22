package projet.fst.ma.jnidemo;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // --- Interface Native "Nexus Engine" ---
    // Ces méthodes sont implémentées en C++ dans native-lib.cpp
    public native String obtenirMessageNexus();
    public native int calculerFactorielleNexus(int n);
    public native String inverserTexteNexus(String s);
    public native int sommerDonneesNexus(int[] valeurs);

    static {
        // Chargement du moteur natif compilé
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 1. Initialisation de la Barre d'outilssss (Toolbar)
        Toolbar barreOutilsNexus = findViewById(R.id.nexusMainToolbar);
        setSupportActionBar(barreOutilsNexus);

        // 2. Liaisonnnn des composantssss UI (Views)
        TextView vueStatut = findViewById(R.id.nexusStatusHeader);
        TextView vueResultatMath = findViewById(R.id.nexusMathResult);
        TextView vueResultatTexte = findViewById(R.id.nexusStringResult);
        TextView vueResultatTableau = findViewById(R.id.nexusArrayResult);

        // 3. Exécution des opérations via le moteur C++ (JNI)

        // Statut du système
        String messageeeStatutt = obtenirMessageNexus();
        vueStatut.setText(messageeeStatutt);

        // Calcul Mathématique
        int valeur__Entree = 10;
        int resultatt__Math = calculerFactorielleNexus(valeur__Entree);
        vueResultatMath.setText(getString(R.string.fmt_factorial, resultatt__Math));

        // Transformation de chaîne
        String texte__Brutt = "Nexus Engine Active";
        String texteTransforme = inverserTexteNexus(texte__Brutt);
        vueResultatTexte.setText(getString(R.string.fmt_reverse, texteTransforme));

        // Traitementttt de données
        int[] donneess = {10, 20, 30, 40, 50};
        int sommee__Totale = sommerDonneesNexus(donneess);
        vueResultatTableau.setText(getString(R.string.fmt_array, sommee__Totale));
    }
}
