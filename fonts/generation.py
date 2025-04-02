from PIL import Image, ImageDraw, ImageFont

def generate_spritesheet(font_path, output_filename, img_size=48, cols=16):
    """
    Génère une spritesheet ASCII (128 caractères) avec des lettres centrées et bien visibles.

    :param font_path: Chemin vers la police (.ttf)
    :param output_filename: Nom du fichier de sortie (.png)
    :param img_size: Taille de chaque case dans la spritesheet
    :param cols: Nombre de colonnes dans la spritesheet
    """
    rows = (128 + cols - 1) // cols  # Nombre de lignes nécessaires (arrondi)

    # Déterminer dynamiquement la taille de la police pour ne pas couper les lettres
    font_size = int(img_size * 0.5)  # 70% de la taille de la case pour éviter la coupe
    font = ImageFont.truetype(font_path, font_size)

    # Créer une image pour la spritesheet
    spritesheet = Image.new("RGBA", (cols * img_size, rows * img_size), (0, 0, 0, 0))

    # Dessiner chaque caractère ASCII
    for i in range(128):
        x = (i % cols) * img_size
        y = (i // cols) * img_size
        char = chr(i)

        # Créer une image temporaire pour dessiner le caractère
        temp_img = Image.new("RGBA", (img_size, img_size), (0, 0, 0, 0))
        temp_draw = ImageDraw.Draw(temp_img)

        # Obtenir la taille exacte du texte
        bbox = temp_draw.textbbox((0, 0), char, font=font)
        text_w, text_h = bbox[2] - bbox[0], bbox[3] - bbox[1]

        # Calculer la position pour centrer le texte
        text_x = (img_size - text_w) // 2
        text_y = (img_size - text_h) // 2

        # Dessiner le texte centré
        temp_draw.text((text_x, text_y), char, font=font, fill="white")

        # Ajouter la lettre à la spritesheet
        spritesheet.paste(temp_img, (x, y))

    # Sauvegarde
    spritesheet.save(output_filename)
    print(f"✅ Spritesheet générée : {output_filename}")

if __name__ == "__main__":
    # Modifier ces paramètres selon ton besoin
    font_path = "font.otf"  # Change pour la police de ton choix
    output_filename = "ascii_spritesheet_48x48.png"

    generate_spritesheet(font_path, output_filename, 32)
