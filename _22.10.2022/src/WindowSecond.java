import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Random;

public class WindowSecond extends JFrame {

    WindowSecond(String str){
        super(str);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        JLabel question = new JLabel("Ты гей?");
        add(question);
        JButton yes = new JButton("Конечно");
        add(yes);
        JButton no = new JButton("Пошёл нахуй");
        add(no);
        yes.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(Window.getWindows()[0], "Я так и думал.", "Хорош!", JOptionPane.INFORMATION_MESSAGE);
            }
        });
        Random random = new Random();
        no.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                no.setLocation(random.nextInt(15, getWidth() - no.getWidth()), random.nextInt(0, getHeight() - no.getHeight()));
            }
            @Override
            public void mouseMoved(MouseEvent e){
                no.setLocation(random.nextInt(15, getWidth() - no.getWidth()), random.nextInt(0, getHeight() - no.getHeight()));
            }

        });
    }
    public static void main(String[] args) {
        WindowSecond a = new WindowSecond("привет");
        a.pack();
        a.setSize(400, 300);
        a.setLocation(500, 50);
        a.setVisible(true);
    }
}
