using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Serial_Example
{
    public partial class Form1 : Form
    {
        string DataOut;
        string DataIn;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Get a list of serial port names and returns them in an array of strings called ports {COM1,COM2,etc.}.
            string[] ports = SerialPort.GetPortNames();
            
            //put portnames in the combo box list
            cboxcomport.Items.AddRange(ports);

            //initial conditions
            chkboxdtr.Checked = false;
            serialPort1.DtrEnable = false;
            chkboxrts.Checked = false;
            serialPort1.RtsEnable = false;
        }

        private void btnopen_Click(object sender, EventArgs e)
        {
            try {
                //name serialport1 as chosen in combo box.
                //put baud rate of serial port 1 as choosen in cbox.
                
                serialPort1.PortName = cboxcomport.Text;
                serialPort1.BaudRate = Convert.ToInt32(cboxbaudrate.Text);
                serialPort1.DataBits = Convert.ToInt32(cboxdatabits.Text);
                //  We call Enum.Parse.The typeof(StopBits) returns the enum type.
                // We cast the result of Enum.Parse to the StopBits enum type.
                serialPort1.StopBits = (StopBits)Enum.Parse(typeof(StopBits), cboxstopbits.Text);
                serialPort1.Parity   = (Parity)Enum.Parse(typeof(Parity), cboxparitybits.Text);

                //open SERIALPORT1 After initialization.
                serialPort1.Open();
                progressBar1.Value = 100;
                lblonoff.Text = "ON";
                radbtnaddon.Checked = true;
                radbtnalwaysup.Checked = false;
                /* chkboxaddonlast.Checked = true;
                chkboxalwaysupdate.Checked = false;
                */
            }

            catch(Exception err)
            {
                MessageBox.Show(err.Message,"error!!!", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void cboxcomport_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void tboxdataout_TextChanged(object sender, EventArgs e)
        {
            //get length of what's in text box OUT
            int dataoutlength = tboxdataout.TextLength;
            //Show it on label in double digits format
            lbldataoutlength.Text = string.Format("{0:00}", dataoutlength);
        }

        private void btnclose_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                progressBar1.Value = 0;
                lblonoff.Text = "OFF";
            }
        }

        private void btnsenddata_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                //takes data from Text Box in DataOut and sends it on SerialPort1.
                DataOut = tboxdataout.Text;
                //serialPort1.WriteLine(DataOut);
                serialPort1.Write(DataOut);
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (chkboxrts.Checked)
            {
                serialPort1.RtsEnable = true;
            }
            else
            {
                serialPort1.RtsEnable = false;
            }

        }

        private void chkboxdtr_CheckedChanged(object sender, EventArgs e)
        {
            if (chkboxdtr.Checked)
            {
                serialPort1.DtrEnable = true;
            }
            else
            {
                serialPort1.DtrEnable = false;
            }
        }

        private void btndataclr_Click(object sender, EventArgs e)
        {
            if(tboxdataout.Text != "")
            {
                //Empty Textbox
                tboxdataout.Text =  "";
            }
        }

        private void lbldataoutlength_Click(object sender, EventArgs e)
        {

        }

        private void btndatatx_Click(object sender, EventArgs e)
        {
            DataOut = tboxdataout.Text;
            serialPort1.WriteLine(DataOut);
            /*
            serialPort1.Write(DataOut); 
            */
        }

        private void lblonoff_Click(object sender, EventArgs e)
        {

        }
        //SERIAL PORT AS A RECIEVEING TERMINAL
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            DataIn = serialPort1.ReadExisting();
            this.Invoke(new EventHandler(showdata));
        }

        private void showdata(object sender, EventArgs e)
        {
            
            if (radbtnalwaysup.Checked)
            {
                txtboxdatain.Text = DataIn;
            }
            else if (radbtnaddon.Checked)
            {
                txtboxdatain.Text += DataIn;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if(txtboxdatain.Text != "")
            {
                txtboxdatain.Text = "";
            }
        }

        private void txtboxdatain_TextChanged(object sender, EventArgs e)
        {
            int datainlength = txtboxdatain.TextLength;
            lbldatainlength.Text = string.Format("{0,00}", datainlength);
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radbtnalwaysup.Checked)
            {
                ///////////////// instead of chk box
                radbtnalwaysup.Checked = true;
                radbtnaddon.Checked = false;
            }
            else
            {
                radbtnaddon.Checked = true;
            }
        }

        private void radbtnaddon_CheckedChanged(object sender, EventArgs e)
        {
            if (radbtnaddon.Checked)
            {
                /////////////////////////////
                radbtnaddon.Checked = true;
                radbtnalwaysup.Checked = false;
            }
            else
            {
                radbtnalwaysup.Checked = true;
            }
        }
    }
}
