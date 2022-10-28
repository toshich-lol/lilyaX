import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Window extends JFrame{
    private final JButton button;
    private final JLabel status;
    Window(String str) {
        super(str);
        button = new JButton("Click");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        status = new JLabel();
        add(status, BorderLayout.SOUTH);
        JPanel panel = new JPanel();
        panel.setLayout(null);
        add(panel, BorderLayout.CENTER);
        button.setSize(button.getPreferredSize());
        panel.add(button);

        panel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                setStatus(e.getX(), e.getY());
                button.setLocation(e.getX(), e.getY());
            }
        });

        panel.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                setStatus(e.getX(), e.getY());
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                mouseMoved(e);
            }
        });

        button.addMouseMotionListener(new MouseMotionAdapter() {
            @Override
            public void mouseMoved(MouseEvent e) {
                setStatus(e.getX() + button.getX(), e.getY() + button.getY());
            }

            @Override
            public void mouseDragged(MouseEvent e) {
                if (e.isControlDown()) {
                    button.setLocation(e.getX() + button.getX(), e.getY() + button.getY());
                    setStatus(e.getX() + button.getX(), e.getY() + button.getY());
                }
            }
        });
    }

    void setStatus(int x, int y){
        status.setText("x: " + x + ", y: " + y);
    }

    public static void main(String[] args) {
        Window a = new Window("привет");
        a.pack();
        a.setSize(1000, 700);
        a.setLocation(500, 50);
        a.setVisible(true);
    }
}





